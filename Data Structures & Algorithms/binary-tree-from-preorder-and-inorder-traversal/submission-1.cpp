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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>hashmap;
        for(int i=0;i<inorder.size();i++)
        {
            hashmap[inorder[i]]=i;
        }
        return buildtree(preorder,0,preorder.size()-1,
        inorder,0,inorder.size()-1,hashmap);
         
    }
    TreeNode*buildtree(vector<int>& preorder,int prestart,int preend,
    vector<int>& inorder,int instart,int inend,
    map<int,int>hashmap)
    {
        if(prestart>preend||instart>inend)return NULL;

        TreeNode*root=new TreeNode(preorder[prestart]);
        int inroot=hashmap[root->val];
        int numsleft =inroot-instart;
        root->left=buildtree(preorder,prestart+1,prestart+numsleft,
        inorder,instart,inroot-1,hashmap);
        root->right=buildtree(preorder,prestart+numsleft+1,preend,
        inorder,inroot+1,inend,hashmap);
        return root;
    }
};
