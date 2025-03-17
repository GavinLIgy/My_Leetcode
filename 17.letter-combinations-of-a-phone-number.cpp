/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:

    string digit2char (char c_){
        switch(c_){
            case '2': 
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            //case '9':
            default:
                return "wxyz";
        }
    }


    vector<string> letterCombinations(string digits) {
        // my
        /* 
        vector<string> res, temp;
        res.resize(0);
        if (digits.length()==0) return res;
        for (int i=0; i<digits.length(); i++){
            string chars_ = digit2char(digits[digits.length() - 1 - i]);
            if (res.size() > 0){
                temp.assign(res.begin(), res.end());
                res.resize(0);
                for (char char_: chars_ ){
                    for (string pat_: temp ){
                        string s = string() + char_;
                        s.append(pat_);
                        res.push_back(s);
                    }
                }
            } else {
                for (char char_: chars_ ){
                    string s = string() + char_;
                    res.push_back(s);
                }
            }
        } 
            
        return res;
            */
        // backtrack
        if (digits.empty()) return {};
        std::vector<std::string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> combinations;
        backtrack(0, digits, "", combinations, phone_map);
        return combinations;

        //hash table
        
    }

private:
    void backtrack(int index, const std::string& digits, std::string path, std::vector<std::string>& combinations, const std::vector<std::string>& phone_map) {
        if (index == digits.size()) {
            combinations.push_back(path);
            return;
        }
        std::string possible_letters = phone_map[digits[index] - '2'];
        for (char letter : possible_letters) {
            backtrack(index + 1, digits, path + letter, combinations, phone_map);
        }
    }
};
// @lc code=end

