class Solution {
public:
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),ans=-1;
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        queue<pair<int,int>>q;
        q.push({0,0});
        int l=1;
        
        while(!q.empty())
        {
             int k=q.size();
             for(int i=0;i<k;i++)
             {
                 int x=q.front().first;
                 int y=q.front().second;
                 q.pop();
                 
                 if(x==n-1 && y==n-1)
                 {
                     ans=l;
                     break;
                 }
                 
                 for(int j=0;j<8;j++)
                 {
                    int a=x+dx[j];
                    int b=y+dy[j];

                    if(a>=0 && b>=0 && a<n && b<n && grid[a][b]==0 && !vis[a][b])
                    {
                        vis[a][b]=1;
                        q.push({a,b});
                    }
                 }
             }
            l++;
        }
        
        return ans;
    }
};