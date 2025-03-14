/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.size(), ans=0;
        unordered_map<char, int> freq;
        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]] > 1){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
// @lc code=end

