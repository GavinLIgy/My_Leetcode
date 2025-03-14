/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);

        vector<int> resL = rightSideView(root->left);
        vector<int> resR = rightSideView(root->right);

        int i = 0;
        for(int ele : resR){
            res.push_back(ele);
            i++;
        }

        if(resL.size() > resR.size()){
            for(;i<resL.size();i++){
                res.push_back(resL[i]);
            }
        }

        return res;
    }
};
// @lc code=end

