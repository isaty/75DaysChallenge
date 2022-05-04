class Solution {
public:
    //count subset with given sum
    int helper(vector<int>& arr, int n, int sum,vector<vector<int>>&dp)
	{
	    if(n==0)
        {
            if(sum==0)
            return 1;
            
            return 0;
        }
        
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        if(arr[n-1]<=sum)
        {
            return dp[n][sum]=(helper(arr,n-1,sum-arr[n-1],dp)+helper(arr,n-1,sum,dp));
        }
        
        return dp[n][sum]=helper(arr,n-1,sum,dp);
	}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
         int sum=0,n=nums.size();
         sum=accumulate(nums.begin(),nums.end(),sum);
         
        if(sum<abs(target) || (target+sum)%2!=0)
            return 0;
        
         int sumSub1=(sum+target)/2;
    
         vector<vector<int>>dp(n+1,vector<int>(sumSub1+1,-1));
         helper(nums,n,sumSub1,dp);
         return dp[n][sumSub1];
        
    }
};