class Solution {
public:
    int dfs(int n,int target,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(n==0)
            return INT_MAX-1;
        
        if(target==0)
            return 0;
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        if(coins[n-1]<=target)
        {
            return dp[n][target]=min(1+dfs(n,target-coins[n-1],coins,dp),dfs(n-1,target,coins,dp));
        }
        
        return dp[n][target]=dfs(n-1,target,coins,dp);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=dfs(n,amount,coins,dp);
        return ans!=INT_MAX-1 ? ans:-1;
    }
};