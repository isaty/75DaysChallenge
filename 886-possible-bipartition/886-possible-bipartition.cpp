class Solution {
public:
    vector<int>adj[2001];
    int vis[2001];
    
    bool dfs(int u,int col,vector<int>&color)
    {
        vis[u]=1;
        color[u]=col;
        
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                int cl=1^col;
                bool k=dfs(v,cl,color);
                
                if(!k)
                    return false;
            }
            else if(vis[v] && col==color[v])
            {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>color(n+1,-1);
        for(vector<int>i: dislikes)
        {
            adj[i[0]].push_back(i[1]);
             adj[i[1]].push_back(i[0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && !dfs(i,0,color))
            return false;
        }
        return true;
    }
};