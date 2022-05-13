// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
     int cuts(int price[], int n,int portion,vector<vector<int>>&dp)
     {
         if(n==0 || portion==0)
           return 0;
           
         if(dp[n][portion]!=-1)
         return dp[n][portion];
         
         if(portion>=n)
         {
             return dp[n][portion]=max(price[n-1]+cuts(price,portion-n,portion-n,dp),cuts(price,n-1,portion,dp));
         }
         
         return dp[n][portion]=cuts(price,n-1,portion,dp);
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