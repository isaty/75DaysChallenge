class Solution {
public:
    vector<string>ans;
    void dfs(string s,int open,int close)
    {
        if(open==0 && close==0)
        {
            ans.push_back(s);
            return;
        }
        
        if(close<open)
            return;
        
        if(open>0)
        dfs(s+"(",open-1,close);
        
        if(close>0)
        dfs(s+")",open,close-1);
    }
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        dfs("",n,n);
        return ans;
    }
};