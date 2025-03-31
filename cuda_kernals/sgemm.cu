#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <vector>
#include <algorithm>
#include <cuda_runtime.h>

#define WARP_SIZE 32
#define INT4(value) (reinterpret_cast<int4*>(&(value))[0])
#define FLOAT4(value) (reinterpret_cast<float4*>(&(value))[0])

// naive imple, compute one c[i,j] element per threads, all row major
__global__ void sgemm_naive_f32_kernel(float* a, float* b, float* c, int M, int N, int K){
    int n = blockIdx.x * blockDim.x + threadIdx.x ;
    int m = blockIdx.y * blockDim.y + threadIdx.y ;

    if(n < N && m < M) {
        float psum = 0.0f;
        #pragma unroll
        for(int k=0; k<K; k++){
            psum += a[m*K + k] * b[k*N + n];
        }
        c[m*N + n] = psum;
    }
}

// block tile + K tile with smem
// block tile (BM, BN) + K tile (BK=32)
// gird((N + BN -1) / BN, (M + BM -1) / BM), block(BN, BM)
// a: M x K, b: K x N, c: M x N, compute: c = a*b, all row major
template<const int BM = 32, const int BN = 32, const int BK = 32>
__global__ void sgemm_sliced_k_f32_kernel(float* a, float* b, float* c, int M, int N, int K){
    // [1] Block tile: using 32 x 32 block for c element
    // [2] k tile: using shared memory, tile k elements into bk-elements tiles
    // constexpr int BM = 32;
    // constexpr int BN = 32;
    // constexpr int BK = 32;
    __shared__ float s_a[BM][BK], s_b[BK][BN];

    int bx = blockIdx.x;
    int by = blockIdx.y;
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    int tid = threadIdx.y * blockDim.x + tx; // tid within the block
    // load values to shared memory, 32x32 threads working together 
    // to fetch data along the row direction of a and b both for s_a 
    // and s_b 32x32x4x2=8KB, we use 32x32 threads within block to 
    // load 32x32 elements from global memory to shared memory, namely, 
    // each thread will load 1 element.
    int load_smem_a_m = tid / 32; // tid / BM, threadIdx.y
    int load_smem_a_k = tid % 32; // tid % BK, threadIdx.x
    int load_smem_b_k = tid / 32; // tid / BK, threadIdx.y
    int load_smem_b_n = tid % 32; // tid % BN, threadIdx.x
    int load_gmem_a_m = by * BM + load_smem_a_m; // global row of a and c
    int load_gmem_b_n = bx * BN + load_smem_b_n; // global col of b and c
    if (load_gmem_a_m >= M || load_gmem_b_n >= N) return;

    float sum = 0.f;
    for(int bk=0; bk < (K + BK - 1) / BK; ++bk){
        int load_gemm_a_k = bk * BK + load_smem_a_k;
        int load_gemm_a_addr = load_gmem_a_m * K + load_gemm_a_k;// row major
        s_a[load_smem_a_m][load_smem_a_k] = a[load_gemm_a_addr];
        int load_gemm_b_k = bk * BK + load_smem_b_k;
        int load_gemm_b_addr = load_gemm_b_k * N + load_gemm_b_n;
        s_a[load_smem_b_k][load_smem_b_n] = a[load_gemm_b_addr];
        __syncthreads();
        #pragma unroll
        for(int k=0; k<BK; ++k){
            int comp_smem_a_m = load_smem_a_m;
            int comp_smem_b_n = load_smem_b_n;
            sum += s_a[comp_smem_a_m][k] * s_b[k][comp_smem_b_n];
        }
        __syncthreads();
    }
    int store_gemm_c_m = load_gmem_a_m;
    int store_gemm_c_n = load_gmem_b_n;
    int store_genn_c_addr = store_gemm_c_m * N + store_gemm_c_n;
    c[store_genn_c_addr] = sum;
}
