class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int ans=-1;
        vector<pair<int,int>>adj[n+1];
        for(vector<int>i:times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
    
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>q;
        q.push({0,k});
        dis[k]=0;
        
        while(!q.empty())
        {
            int u=q.top().second;
            int d=q.top().first;
            q.pop();
            
            for(auto i:adj[u])
            {
                if(dis[i.first]>i.second+d)
                {
                    dis[i.first]=i.second+d;
                    q.push({d+i.second,i.first});
                }
            }
            
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};