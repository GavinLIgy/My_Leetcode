/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        TreeNode* right = root->right;

        flatten(root->left);

        // cout << root->val <<endl;
        if (root->left != NULL){
            root->right = root->left;
            root->left = NULL;

            // TreeNode* ptr = root->right;
            TreeNode* prev = root;
            while ((prev != NULL) && (prev->right != NULL)) {
                // ptr = ptr->right;
                prev = prev->right;
            }
            prev->right = right;
        } 

        flatten(right);
    }
    // [1,2,5,3,4,null,6]
};
// @lc code=end

