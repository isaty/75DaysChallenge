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
    TreeNode* last=NULL;
    int getMinimumDifference(TreeNode* root) {
        
        if(root==NULL)
            return INT_MAX;
        
        int l=getMinimumDifference(root->left);
        int ans=INT_MAX;
        if(last)
        {
            ans=abs(last->val-root->val);
            // cout<<ans<<" ";
        }
        last=root;
        int r=getMinimumDifference(root->right);
        return min(ans,min(l,r));
    }
};