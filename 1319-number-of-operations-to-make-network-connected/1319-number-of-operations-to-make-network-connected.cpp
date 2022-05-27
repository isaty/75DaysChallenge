class Solution {
public:
    vector<int>adj[100001];
    int vis[100001];
    void dfs(int curr)
    {
        vis[curr]=1;
        for(int v:adj[curr])
        {
            if(!vis[v])
            {
                dfs(v);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=connections.size();
        int cnt=0;
        
        if(edges<n-1)
            return -1;
        
        for(vector<int>i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        
        return cnt-1;
    }
};