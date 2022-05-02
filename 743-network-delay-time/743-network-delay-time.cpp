class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int ans=-1;
        vector<pair<int,int>>adj[n+1];
        for(vector<int>i:times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,k});
        dis[k]=0;
        vis[k]=1;
        
        while(!q.empty())
        {
            int u=q.front().second;
            int d=q.front().first;
            q.pop();
            
            for(auto i:adj[u])
            {
                if(dis[i.first]>i.second+d)
                {
                    dis[i.first]=i.second+d;
                    q.push({d+i.second,i.first});
                    vis[i.first]=1;
                }
            }
            
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};