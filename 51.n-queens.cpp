/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> nQueens(n, string(n, '.'));
        back(0, n, nQueens);
        return res;
    }

    vector<vector<string>> res;
private:
    bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
        for(int i=0; i<n; i++) {
            if(nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }
        // If no conflicts found, position is safe
        return true;
    }

    void back(int row, int n, vector<string>& nQueens){
        if (row == n){
            res.push_back(nQueens);
        }
        for(int col=0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col)) {
                // Place queen
                nQueens[row][col] = 'Q';
                // Recursively solve for next row
                back(row+1, n, nQueens);
                // Backtrack: remove queen for trying next position
                nQueens[row][col] = '.';
            }

        }

    }


};
// @lc code=end

