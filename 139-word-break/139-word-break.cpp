class Solution {
public:
    
    unordered_set<string>dict;
    
    bool word(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)
            return false;
        
        if(dict.find(s.substr(i,j-i+1))!=dict.end())
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=i;k<j;k++)
        {
            if(dict.find(s.substr(i,k-i+1))!=dict.end() && word(s,k+1,j,dp))
                return dp[i][j]=1;
        }
        
        return dp[i][j]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        
        for(string str:wordDict)
            dict.insert(str);
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            
        return word(s,0,s.length()-1,dp);
    }
};