class Solution {
public:
    int n;
    void dfs(int curr,vector<vector<int>>& isConnected,vector<int>&vis)
    {
        vis[curr]=1;
        for(int i=0;i<n;i++)
        {
            if(isConnected[curr][i] && !vis[i])
            {
                dfs(i,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int components=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                components++;
            }
        }
        return components;
    }
};