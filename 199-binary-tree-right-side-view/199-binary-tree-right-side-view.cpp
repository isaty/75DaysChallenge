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
    vector<int>res;
    void inorder(TreeNode* root,int l)
    {
        if(root==NULL)
            return;
        
        if(res.size()<=l)
            res.push_back(root->val);
        else
            res[l]=root->val;
        
        inorder(root->left,l+1);
        inorder(root->right,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        inorder(root,0);
        return res;
    }
};