class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>in(n,0);
        vector<int>adj[n];
        vector<int>res;
        queue<int>q;
        
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        
        for(vector<int>i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            in[i[1]]++;
            in[i[0]]++;
        }//egdes to graph
        
       
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==1)
            {
                q.push(i);
            }
        }//initial q push
        
        while(!q.empty())
        {
            res.clear();
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                int t=q.front();
                q.pop();
                res.push_back(t);
                for(int u:adj[t])
                {
                    in[u]--;
                    if(in[u]==1)
                        q.push(u);
                }
            }
        }
        
        return res;
        
    }
};