/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <algorithm>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) return {nums};
        vector<vector<int>> res;
        back(res, 0, nums);
        return res;
    }
private:
    void back (vector<vector<int>>& res, int index, vector<int>& nums){
        if (index == nums.size()){
            res.push_back(nums);
            return;
        }

        for (int j=index; j < nums.size(); j++){
            std::swap(nums[index], nums[j]);
            back(res, index+1, nums);
            std::swap(nums[j], nums[index]);
        }
    }
};
// @lc code=end

