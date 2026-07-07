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
    int traversal(TreeNode*root,int maxval)
    {
        if(root==NULL)return 0;
        int count=0;
        if(root->val>=maxval)
        {
            count++;
            maxval=root->val;
        }
        count+=traversal(root->left,maxval);
        count+=traversal(root->right,maxval);
        return count;
    }
    int goodNodes(TreeNode* root) { 
        return traversal(root,root->val);
    }
};
