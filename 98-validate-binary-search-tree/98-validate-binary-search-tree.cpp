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
    
    bool valid(TreeNode* root,long l,long r)
    {
         if(root==NULL)
             return true;
        
         if(l>=root->val || r<=root->val)
                 return false;
        
        return valid(root->left,l,root->val)&&valid(root->right,root->val,r);
    }
    
    bool isValidBST(TreeNode* root) {
        long l=LONG_MIN,r=LONG_MAX;
        return valid(root,l,r);
    }
};