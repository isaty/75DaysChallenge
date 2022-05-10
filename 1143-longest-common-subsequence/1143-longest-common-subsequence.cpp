class Solution {
public:
    int lcs(int n,int m,string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m]!=-1)
        return dp[n][m];
        
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+lcs(n-1,m-1,s1,s2,dp);
        }
        
        return dp[n][m]=max(lcs(n-1,m,s1,s2,dp),lcs(n,m-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return lcs(text1.length(),text2.length(),text1,text2,dp);
    }
};