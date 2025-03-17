/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int dp [101][101] {};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.length == 1){
            for (int i=0; i<obstacleGrid[1].length; i++){
                if (obstacleGrid[1] == 1) return 0;
            }
            return 1;
        }
        if (obstacleGrid[1].length == 1){
            for (int i=0; i<obstacleGrid.length; i++){
                if (obstacleGrid[1] == 1) return 0;
            }
            return 1;
        }
    }
};
// @lc code=end

