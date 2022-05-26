class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        
        queue<int>q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                int u=q.front();
                q.pop();
                
                for(int v:rooms[u])
                {
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        
        for(int i:vis)
        {
            if(i==0)
                return false;
        }
        return true;
    }
};