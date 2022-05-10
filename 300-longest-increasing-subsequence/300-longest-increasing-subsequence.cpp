class Solution {
public:
    
    int lis(vector<int>& nums,int i,int prev,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
            return 0;
        
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        
        int a=0,b=lis(nums,i+1,prev,dp);
        
        if(prev==-1 || nums[i]>nums[prev])
            a=1+lis(nums,i+1,i,dp);
        
        return dp[i][prev+1]=max(a,b);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lis(nums,0,-1,dp);
    }
};