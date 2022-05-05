// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subsetSum(int arr[],int n,int sum ,vector<vector<int>>&dp)
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
            return dp[n][sum]=subsetSum(arr,n-1,sum-arr[n-1],dp)||subsetSum(arr,n-1,sum,dp);
        }
        
        return dp[n][sum]=subsetSum(arr,n-1,sum,dp);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        sum=accumulate(arr,arr+N,sum);
        
        if(sum%2!=0)
        return 0;
        sum=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return subsetSum(arr,N,sum,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends