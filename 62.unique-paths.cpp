/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    /*
    int uniquePaths(int m, int n) {
        if (m == 1) return 1;
        if (n == 1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
    */
    int dp [101] [101] {};
    int uniquePaths(int m, int n) {
        if (m == 1) return 1;
        if (n == 1) return 1;
        if (dp[m][n]) return dp[m][n];
        return dp[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};
// @lc code=end

