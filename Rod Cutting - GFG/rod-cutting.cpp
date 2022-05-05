// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cuts(int price[],int n,int length,vector<vector<int>>&dp)
    {
        if(n==0||length==0)
        return 0;
        
        if(dp[n][length]!=-1)
        return dp[n][length];
        
        if(length>=n)
        {
            return dp[n][length]=max(price[n-1]+cuts(price,n,length-n,dp),cuts(price,n-1,length,dp));
        }
        
        return dp[n][length]=cuts(price,n-1,length,dp);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return cuts(price,n,n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends