/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool res_inv = (dividend < 0) ^ (divisor < 0);

        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        unsigned int result = 0;

        while (absDividend  >= absDivisor){ 
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)){
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            result += multiple;
        }

        return res_inv ? -result : result;
    }
};
// @lc code=end

