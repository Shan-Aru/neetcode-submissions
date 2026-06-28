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
        vector<int>res;
        recursion_function(root,0,res);
        return res;
    }
    void recursion_function(TreeNode*root,int level,vector<int>&res)
    {
        if(root==NULL)return;
        if(level==res.size())res.push_back(root->val);
        recursion_function(root->right,level+1,res);
        recursion_function(root->left,level+1,res);
    }
};
