class Solution {
public:
    vector<int>adj[100001];
    int in[100001];
    int vis[100001];
    int low[100001];
    vector<vector<int>>res;
    int time=0;
    
    void dfs(int u,int parent)
    {
        vis[u]=1;
        in[u]=time;
        low[u]=time++;
        
        for(int v:adj[u])
        {
            if(v==parent)continue;
            if(!vis[v])
            {
               //forward edge visit the node and check for bridges
               dfs(v,u);
               
                //check if this was a bridge
                if(low[v] > in[u])
                {
                    res.push_back({u,v});
                }
                
                //check if we can minimize the low time of current edge wit low time of child edge.
                low[u]=min(low[u],low[v]);

            }else{
                low[u]=min(low[u],in[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        for(vector<int>i:connections)
        {
           adj[i[0]].push_back(i[1]);
           adj[i[1]].push_back(i[0]);
        }
        
        dfs(0,-1);
        
        return res;
        
    }
};