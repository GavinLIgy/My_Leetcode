/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int checkLen = s.size(); 

        while (checkLen > 1){
            for (int i=0; i<=s.size()-checkLen; i++){
                if (checkPali(s, i, i+checkLen-1)){
                    return s.substr(i, checkLen);
                }
            }
            checkLen--;
        }

        return s.substr(0, 1);
    }
private:
    bool checkPali(string& s, int start, int end){
        while (start < end){
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
// @lc code=end

