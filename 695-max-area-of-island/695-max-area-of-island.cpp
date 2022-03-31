class Solution {
public:
    int n,m;
    void dfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int &area)
    {
        vis[i][j]=1;
        area++;
        
        if(i>0 && grid[i-1][j]==1 && !vis[i-1][j])
            dfs(i-1,j,grid,vis,area);
        
        if(j>0 && grid[i][j-1]==1 && !vis[i][j-1])
            dfs(i,j-1,grid,vis,area);
        
        if(i+1<n && grid[i+1][j]==1 && !vis[i+1][j])
             dfs(i+1,j,grid,vis,area);
        
        if(j+1<m && grid[i][j+1]==1 && !vis[i][j+1])
             dfs(i,j+1,grid,vis,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
         n=grid.size();
         m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1 && !vis[i][j])
               {
                   int cnt=0;
                   dfs(i,j,grid,vis,cnt);
                   // cout<<i<<" "<<j<<" "<<cnt<<"\n";
                   ans=max(ans,cnt);
               }
            }
        }
        
        return ans;
    }
};