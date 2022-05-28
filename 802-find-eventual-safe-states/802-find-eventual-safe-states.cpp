class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>tr_adj[n];
       vector<int>in(n,0);
       vector<int>res; 
       for(int i=0;i<n;i++)
       {
           for(int j:graph[i])
           {
               tr_adj[j].push_back(i);
               in[i]++;
           }
       } 
       
       queue<int>q;
       for(int i=0;i<n;i++) 
       {
           if(in[i]==0)
           {
               q.push(i);
           }
       }
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                int u=q.front();
                q.pop();
                res.push_back(u);
                
                for(int v:tr_adj[u])
                {
                    in[v]--;
                    
                    if(in[v]==0)
                    {
                       q.push(v); 
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};