/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==1) return {"()"};
        std::vector<std::string> combinations;
        backtrack(n, 0, 0, "", combinations);
        return combinations;
    }
private:
    void backtrack(int n, int openCtr,int closeCtr, std::string path, std::vector<std::string>& combinations) {
        if (openCtr == n && closeCtr == n) {
            combinations.push_back(path);
            return;
        }

        if (openCtr < n) {
            backtrack(n, openCtr+1, closeCtr, path+"(", combinations);
        }
        if (closeCtr<openCtr) {
            backtrack(n, openCtr, closeCtr+1, path+")", combinations);
        }
    }

};
// @lc code=end

