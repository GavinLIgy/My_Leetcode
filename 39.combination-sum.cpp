/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    int T;
    void solve(vector<int> &temp, vector<int>& candidates, int idx){
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if(sum==T){
            ans.push_back(temp);
            return;
        }
        if(sum>T) return;
        for(int i=idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            solve(temp, candidates, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        T=target;
        vector<int> temp;
        solve(temp, candidates,0);
        return ans;
    }
};
// @lc code=end

