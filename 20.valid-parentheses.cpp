/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        stack<char> stack_;

        for (char c : s) {
            if ((c == '(') || (c == '[') || (c == '{')){
                stack_.push(c);
            } else {
                if (!stack_.empty()){
                    char c_ = stack_.top();
                    stack_.pop();
                    if (!(((c == ')') && (c_ == '(')) || \
                    ((c == ']') && (c_ == '[')) || \
                    ((c == '}') && (c_ == '{')))) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return stack_.empty();
    }
};
// @lc code=end

