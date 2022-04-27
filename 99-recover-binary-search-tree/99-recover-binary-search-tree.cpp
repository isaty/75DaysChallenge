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
    TreeNode*pre=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    
    void find(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        find(root->left);
        
        if(pre && root->val < pre->val)
        {
            if(first==NULL)
                first=pre;
            
            second=root;
        }
        pre=root;
        find(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        find(root);
        swap(first->val,second->val);
    }
};