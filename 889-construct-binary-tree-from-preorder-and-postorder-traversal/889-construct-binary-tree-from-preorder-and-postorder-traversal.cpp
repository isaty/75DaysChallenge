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
    unordered_map<int,int>mp;
    TreeNode* tree(vector<int>& preorder,int &i,int l)
    {
        if(i>=preorder.size())
            return NULL;
        
        int p=mp[preorder[i]];
        
        if(p>l)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[i++]);
        
        root->left=tree(preorder,i,p-1);
        root->right=tree(preorder,i,p-1);    
            
        return root;   
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        for(int i=0;i<postorder.size();i++)
            mp[postorder[i]]=i;
        
        int i=0;
        
        return tree(preorder,i,preorder.size()-1);
    }
};