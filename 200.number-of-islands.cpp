/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (dfs(grid, i, j)) res++;
            }
        }

        return res;
    }
private:
    bool dfs(vector<vector<char>>& grid, int x, int y){
        if ((x<0)||(x>grid.size()-1)||(y<0)||(y>grid[0].size()-1)) return false;
        if (grid[x][y] != '1') return false;
        grid[x][y] = '2';
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
        return true;
    }

};
// @lc code=end

