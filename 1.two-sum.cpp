/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> hash_table;

        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if (hash_table.find(complement) != hash_table.end()) {
                return {hash_table[complement], i};
            }
            hash_table[nums[i]] = i;
        }

        return {};

    };
};
// @lc code=end

