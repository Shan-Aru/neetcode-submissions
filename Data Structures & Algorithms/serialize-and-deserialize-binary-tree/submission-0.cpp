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

class Codec {
public:
    void encode(TreeNode*root,string&data)
    {
        if(root==nullptr)
        {
            data+="N,";
            return;
        }
        data+=to_string(root->val)+",";
        encode(root->left,data);
        encode(root->right,data);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        encode(root,data);
        return data;
    }
    TreeNode*decode( vector<string>&nodes,int &i)
    {
        if(nodes[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode*root=new TreeNode(stoi(nodes[i]));
        i++;
        root->left=decode(nodes,i);
        root->right=decode(nodes,i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp="";
        for (char ch:data){
            if(ch==','){
                nodes.push_back(temp);
                temp="";
            }
            else temp+=ch;
        }
        int i=0;
        return decode(nodes,i);
    }
};
