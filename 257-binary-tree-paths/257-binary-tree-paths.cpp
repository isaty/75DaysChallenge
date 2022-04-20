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
    vector<string>ans;
    void paths(TreeNode* root,string str)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            string a=to_string(root->val);
            str+=a;
            ans.push_back(str);
            return;
        }
        
        string a=to_string(root->val);
        str+=a+"->";
        paths(root->left,str);
        paths(root->right,str);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        paths(root,"");
        return ans;
    }
};