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
    unsigned int ans=1;
    unordered_map<int,unsigned int>mp;
    void width(TreeNode* root,int l,unsigned int d)
    {
        if(root==NULL)
            return;
    
        if(mp.find(l)==mp.end())
        {
            mp[l]=d;
        }
        else
        {
            ans=max(d-mp[l]+1,ans);   
        }
        
        width(root->left,l+1,2*d+1);
        width(root->right,l+1,2*d+2);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        width(root,1,0);
        return ans;
    }
};