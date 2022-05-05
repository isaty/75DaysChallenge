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
    
    vector<TreeNode*> helper(int str,int end )
    {
        vector<TreeNode*>list;
        if(str>end)
        {
            list.push_back(NULL);
            return list;
        }
        
        if(str==end)
        {
            list.push_back(new TreeNode(str));
            return list;
        }
        
        for(int i=str;i<=end;i++)
        {
            vector<TreeNode*>ltreeList=helper(str,i-1);
            vector<TreeNode*>rtreeList=helper(i+1,end);
            
            for(TreeNode* l:ltreeList)
            {
                for(TreeNode* r:rtreeList)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    list.push_back(root);
                }
            }
            
        }
        
        return list; 
    }
    
    vector<TreeNode*> generateTrees(int n) {
         return helper(1,n);
    }
};