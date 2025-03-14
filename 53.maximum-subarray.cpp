/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int prev = nums[0];
        int ans = prev;

        for(int i=1; i<nums.size(); i++){
            int curr = max(nums[i], prev + nums[i]);
            ans = max(curr, ans);
            prev = curr;
        }

        return ans;
    }
};
// @lc code=end

