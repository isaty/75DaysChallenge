// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int subset(int arr[], int n,int sum,vector<vector<int>>&dp)
    {
       for(int i=0;i<=n;i++)
         dp[i][0]=1;
       for(int j=1;j<=sum;j++)
         dp[0][j]=0;
         
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(j>=arr[i-1])
               {
                 dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];    
               }
               else
               {
                 dp[i][j]=dp[i-1][j];
               }
           }
       }
       
       return dp[n][sum];
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int sum=0;
	     sum=accumulate(arr,arr+n,sum);
	     
	     vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	     subset(arr,n,sum,dp);
	
	     int mn=INT_MAX;
	     for(int i=0;i<=(sum/2);i++)
	     {
	         if(dp[n][i])
	         mn=min(mn,sum-2*i);
	       //  cout<<dp[n][i]<<" ";
	     }
	     
	     return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends