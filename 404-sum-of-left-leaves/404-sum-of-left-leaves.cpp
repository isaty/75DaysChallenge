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
    int sum(TreeNode* root,int k)
    {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL && k==-1)
            return root->val;
        
        int l=sum(root->left,-1);
        int r=sum(root->right,1);
        
        return l+r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,0);
    }
};