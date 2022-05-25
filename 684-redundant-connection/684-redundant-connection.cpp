class Solution {
public:
    vector<int>res;
    vector<int>adj[1001];
    int c;
    bool dfs(int curr,int parent,vector<int>&vis)
    {
        if(vis[curr])
            return true;
        
        vis[curr]=1;
        
        for(int i:adj[curr])
        {
            if(i!=parent && dfs(i,curr,vis))return true;
        }
        
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();

        for(vector<int>i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            vector<int>vis(n+1,0);
            if(dfs(i[0],0,vis))
            {
                res.push_back(i[0]);
                res.push_back(i[1]);
                break;
            }
        }
        
        return res;
    }
};