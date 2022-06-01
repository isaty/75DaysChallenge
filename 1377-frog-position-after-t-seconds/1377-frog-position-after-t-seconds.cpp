class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    
        vector<int>adj[n+1];
        vector<int>vis(n+1,0);
        unordered_map<int,pair<int,double>>prb;
        unordered_set<int>leaf;
        
        for(vector<int>i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        queue<pair<int,double>>q;
        q.push({1,1.000000});
        vis[1]=1;
        prb[1]={0,1.000000};
        int time=0;
        
        while(!q.empty())
        {
            int k=q.size();
            time++;
            for(int i=0;i<k;i++)
            {
                int u=q.front().first;
                double prob=q.front().second;
                q.pop();
                
                double sz=adj[u].size();
                
                if(u!=1)
                    sz=sz-1;
                 
                if(sz==0)
                {
                    leaf.insert(u);
                    continue;
                }
                
                double curr_prob=prob/sz;
                
                for(int v:adj[u])
                {
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push({v,curr_prob});
                        prb[v]={time,curr_prob};
                        // cout<<v<<" "<<time<<" "<<curr_prob<<"\n";
                    }
                }
            }
            k=true;
        }
        
        if(leaf.find(target)!=leaf.end() && t>=prb[target].first)
            return prb[target].second;
        
        if(prb[target].first==t)
            return prb[target].second;
        // cout<<prb[target].first<<" "<<prb[t].second;
        return 0.00000;
    }
};