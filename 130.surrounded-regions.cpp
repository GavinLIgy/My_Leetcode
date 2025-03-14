/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<2; i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, i*(board.size()-1), j);
            }
        }

        for(int i=0; i<2; i++){
            for(int j=0; j<board.size(); j++){
                dfs(board, j, i*(board[0].size()-1));
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'F') board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y){
        // search all connected 'O' with (x, y)
        if ((x<0)||(x>board.size()-1)||(y<0)||(y>board[0].size()-1)) return;

        if (board[x][y] == 'O') {
            board[x][y] = 'F';
            dfs(board, x-1, y);
            dfs(board, x+1, y);
            dfs(board, x, y-1);
            dfs(board, x, y+1);
        } 
    }
};
// @lc code=end

