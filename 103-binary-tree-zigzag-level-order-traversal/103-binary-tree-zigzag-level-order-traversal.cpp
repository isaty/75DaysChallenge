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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        queue<TreeNode*>q;
        vector<vector<int>>res;
        
        if(root==NULL)
            return res;
        int l=1;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            vector<int>it;
            for(int i=0;i<k;i++)
            {
               TreeNode*t=q.front();
               q.pop();
               
                it.push_back(t->val);
                
               if(t->left)
                   q.push(t->left);
                
               if(t->right)
                   q.push(t->right); 
            }
            
            if(l%2==0)
                reverse(it.begin(),it.end());
            
            res.push_back(it);
           
            l++;
        }
        
        return res;
    }
};