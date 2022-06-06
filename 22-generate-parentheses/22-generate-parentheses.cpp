class Solution {
public:
    vector<string>res;
    
    void dfs(string s,int open,int close)
    {
        if(close==0 && open==0)
        {
            res.push_back(s);
            return;
        }
        
        if(close<open )
            return;
        
        if(open>0)
        dfs(s+"(",open-1,close);
        
        if(close>0)
        dfs(s+")",open,close-1);
    }
    
    vector<string> generateParenthesis(int n) {
        int close=n,open=n;
        string s="(";
        open=n-1;
        dfs(s,open,close);
        return res;
    }
};