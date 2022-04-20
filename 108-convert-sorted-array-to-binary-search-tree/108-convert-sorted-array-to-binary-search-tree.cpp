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
    TreeNode* convert(int l, int r, vector<int>& nums)
    {
           if(l>r)
               return NULL;
        
           int mid=l+(r-l)/2;
           TreeNode*root=new TreeNode(nums[mid]);
           root->left=convert(l,mid-1,nums);
           root->right=convert(mid+1,r,nums);
           
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        return convert(l,r,nums);
    }
};