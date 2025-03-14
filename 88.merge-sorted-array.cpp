/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1; 
        int j=n-1;
        int k=n+m-1;
        while((k >= 0) && (i>=0) && (j>=0)){
            if (nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        if (j<0){
            return;
        }
        if (i<0){
            //nums1 = nums2;
            for (; j>=0; --j){
                nums1[j] = nums2[j];
            }
            return;
        }
    }
};
// @lc code=end

