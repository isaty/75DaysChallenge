class Solution {
public:
    bool isvalid(int row,int col,char num,vector<vector<char>>& board)
    {
         //current row
         for(int i=0;i<9;i++)
             if(board[i][col]==num)
                 return false;
        
         //current column
          for(int i=0;i<9;i++)
             if(board[row][i]==num)
                 return false;
        
        //current block
        int x=(row/3)*3;
        int y=(col/3)*3;
        
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
               if(board[i][j]==num)
                 return false; 
            }
        }   
        return true;
    }
    bool solve(int i, int j,vector<vector<char>>& board)
    {
        if(i==9)
            return true;
        if(j==9)
            return solve(i+1,0,board);
        
        if(board[i][j]!='.')
            return solve(i,j+1,board);
        
        for(char c='1';c<='9';c++)
        {
            if(isvalid(i,j,c,board))
            {
                board[i][j]=c;
                if(solve(i,j+1,board))return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};