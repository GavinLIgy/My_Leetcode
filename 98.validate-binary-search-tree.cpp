/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool util(TreeNode* root, long min, long max){
        if (!root) return true;
        if (root->val > min && root->val < max ){
            return util(root->left, min, root->val) && util(root->right,root->val, max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return util(root, LONG_MIN, LONG_MAX);
    };
};
// @lc code=end

