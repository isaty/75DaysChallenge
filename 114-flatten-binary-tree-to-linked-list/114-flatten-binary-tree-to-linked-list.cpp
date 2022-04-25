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
    TreeNode* head=NULL;
    TreeNode* tail=NULL;
    
    void flat(TreeNode* root)
    {
        if(root==NULL)
            return;
        
         TreeNode*l=root->left;
         TreeNode*r=root->right;
         
        if(head==NULL && tail==NULL)
         {
             head=root;
             tail=root;
             tail->left=NULL;
         }
         else
         {
             tail->right=root;
             tail=tail->right;
             tail->left=NULL;
             
         }
        flat(l);
        flat(r);
    }
    void flatten(TreeNode* root) {
        flat(root);
        root=head;
        
    }
};