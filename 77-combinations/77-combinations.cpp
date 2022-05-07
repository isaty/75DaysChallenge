class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>out,vector<int>&num,int i,int n,int k)
    {
        if(out.size()==k)
        {
            res.push_back(out);
            return;
        }
        
        if(i>=n )
            return;
        
        for(int j=i;j<n;j++)
        {
            out.push_back(num[j]);
            dfs(out,num,j+1,n,k);
            out.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
       
        vector<int>num;
        
        for(int i=1;i<=n;i++)num.push_back(i);
        vector<int>out;
        dfs(out,num,0,n,k);
        return res;
    }
};