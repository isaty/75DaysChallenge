class Solution {
public:
    
    int numcoins(vector<int>& coins,int n,int amount,vector<vector<int>>&dp)
    {
        if(amount==0)
           return 0;
        
        if(n==0)
            return INT_MAX-1;
        
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        if(amount>=coins[n-1])
        {
            return dp[n][amount]=min(1+numcoins(coins,n,amount-coins[n-1],dp),numcoins(coins,n-1,amount,dp));
        }
        
        return dp[n][amount]=numcoins(coins,n-1,amount,dp);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
          vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
          int num=numcoins(coins,coins.size(),amount,dp);
          return num==INT_MAX-1? -1:num ;    
    }
};