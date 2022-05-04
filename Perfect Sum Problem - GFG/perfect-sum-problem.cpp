// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int md=1e9+7;
	int helper(int arr[], int n, int sum,vector<vector<int>>&dp)
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
            return dp[n][sum]=(helper(arr,n-1,sum-arr[n-1],dp)+helper(arr,n-1,sum,dp))%md;
        }
        
        return dp[n][sum]=helper(arr,n-1,sum,dp)%md;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(arr,n,sum,dp);
	}
	
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends