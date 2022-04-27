/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=NULL;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode*t=q.front();
                q.pop();
                if(t->left)
                {
                    parent[t->left]=t;
                    q.push(t->left);
                }   
                if(t->right)
                {
                    parent[t->right]=t;
                    q.push(t->right);
                }
            }
        }
        unordered_set<TreeNode*>vis;
        vis.insert(target);
        q.push(target);
        while(k-- && !q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode*t=q.front();
                q.pop();
                
                if(parent[t]!=NULL && vis.find(parent[t])==vis.end())
                {
                    vis.insert(parent[t]);
                    q.push(parent[t]);
                }
                if(t->left && vis.find(t->left)==vis.end())
                {
                    vis.insert(t->left);
                    q.push(t->left);
                }   
                if(t->right && vis.find(t->right)==vis.end())
                {
                    vis.insert(t->right);
                    q.push(t->right);
                }
            }
        }
        
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
       
        return res;
    }
};