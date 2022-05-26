class Solution {
public:
    bool bipartite(int u,int color,vector<vector<int>>& graph,vector<int>&col,vector<int>&vis)
    {
        vis[u]=1;
        col[u]=color;
        
        for(int v:graph[u])
        {
            if(!vis[v])
            {
                int colour=1^color;
                bool k=bipartite(v,colour,graph,col,vis);
                
                if(!k)
                    return false;
            }
            else if(vis[u] && color==col[v])
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n+1,-1);
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!bipartite(i,0,graph,col,vis))
                    return false;
            }
        }
        return true;
    }
};