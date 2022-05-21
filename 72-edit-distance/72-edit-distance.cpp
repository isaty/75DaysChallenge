class Solution {
public:
    int dis(string &word1, string &word2,int n,int m, vector<vector<int>>&dp)
    {
        if(n==0)
            return m;
        
        if(m==0)
            return n;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(word1[n-1]==word2[m-1])
        {
           return dp[n][m]=dis(word1,word2,n-1,m-1,dp); 
        }
        
        ///insert->delete->replace
        return dp[n][m]=1+min(min(dis(word1,word2,n,m-1,dp),dis(word1,word2,n-1,m,dp)),dis(word1,word2,n-1,m-1,dp));
 }
    
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dis(word1,word2,n,m,dp);
    }
};