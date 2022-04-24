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
    int ans=0;
    void dfs(TreeNode*root,long sum,int target,unordered_map<long,int>mp)
    {
        if(root==NULL)
            return;
        
       
        sum+=root->val;
        ans+=mp[sum-target];
        mp[sum]++;
        
        dfs(root->left,sum,target,mp);
        dfs(root->right,sum,target,mp);
       
    }
    
    int pathSum(TreeNode* root, int target) {
        unordered_map<long,int>mp;
        mp[0]++;
        dfs(root,0,target,mp);
        return ans;
    }
};