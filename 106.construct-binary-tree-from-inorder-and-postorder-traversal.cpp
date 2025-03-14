/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in_map;
        for (int i=0;i<inorder.size();i++){
            in_map[inorder[i]] = i;
        }
        return helper(inorder, postorder, in_map, 0, inorder.size()-1, inorder.size()-1);
    };

private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,          
        unordered_map<int, int>& in_map, int i, int j, int k){
        
        if (i == j){
            return new TreeNode(inorder[i]);
        }

        for (int t = k; t >= 0; t--){
            if(in_map[postorder[t]] >= i && in_map[postorder[t]] <= j){
                TreeNode* root = new TreeNode(postorder[t]);
                root -> left = helper(inorder, postorder, in_map, i, in_map[postorder[t]]-1, t-1);
                root -> right = helper(inorder, postorder, in_map, in_map[postorder[t]]+1, j, t-1);
                
                return root;
            }
        }

        return NULL;
    }
    // [9,3,15,20,7]\n[9,15,7,20,3]
    // [2,1]\n[2,1]
};
// @lc code=end

