class Solution {
public:
    
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int one=0;
                for(int k=0;k<8;k++)
                {
                    int a=i+dx[k];
                    int b=j+dy[k];
                    if(a>=0 && b>=0 && a<m && b<n)
                    {
                        if(board[a][b]>=1)
                            one++;

                    }
                }
                // cout<<board[i][j]<<" "<<one<<"\n";
                //living cell with underpopulation
                if(board[i][j]==1 && one<2)
                {
                   board[i][j]=2;   
                }
                //living cell for next generation
                else if(board[i][j]==1 && one>=2 && one<=3)
                {
                    board[i][j]=1;
                }
                //living cell overpopulation
                else if(board[i][j]==1 && one>3 )
                {
                    board[i][j]=2;
                }
                //dead cell becomes living
                else if(board[i][j]==0 && one==3)
                {
                    board[i][j]=-1;
                }
            }
            
        }
        
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==-1)
                    board[i][j]=1;
                else if(board[i][j]==2)
                    board[i][j]=0;
            }
         }
        
    }
};