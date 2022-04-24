/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=NULL;
    
    bool find(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return 0;
        
        int l=find(root->left,p,q);
        int r=find(root->right,p,q);
        int m=(root==p)||(root==q);
        
        if(m+l+r>=2)
            ans=root;
        
        return (m+l+r>0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        find(root,p,q);
        return ans;
    }
};