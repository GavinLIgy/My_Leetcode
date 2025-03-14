/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> resPath;
        vector<int> oneResPath;
        if (root == NULL) return resPath;

        oneResPath.push_back(root->val);

        if (root->val == targetSum){
            if((root->left == NULL) && (root->right == NULL)) {
                resPath.push_back(oneResPath);
            } 
        } 
        
        vector<vector<int>> resPathL = pathSum(root->left, targetSum - root->val);
        vector<vector<int>> resPathR = pathSum(root->right, targetSum - root->val);
        resPathL.insert(resPathL.end(), resPathR.begin(), resPathR.end());
        
        for(int i=0; i<resPathL.size(); i++){
            vector<int> onePath = oneResPath;
            onePath.insert(onePath.end(), resPathL[i].begin(), resPathL[i].end());
            resPath.push_back(onePath);
        }
        
        return resPath;
        //[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22
        //[1,-2,-3,1,3,-2,null,-1]\n-1
    }
};
// @lc code=end

