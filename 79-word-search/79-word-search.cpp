class Solution {
public:
    int vis[7][7];
    int mn,mm;
    
    bool check(int i,int j,int l,vector<vector<char>>& board, string word)
    {
            vis[i][j]=1;
        
            if(l>=word.length())
                return true;
        
            bool k=false;
          
           if(i>0 && !vis[i-1][j] && board[i-1][j]==word[l])
               k=check(i-1,j,l+1,board,word);
         
           if(!k && j>0 && !vis[i][j-1] && board[i][j-1]==word[l])
               k=check(i,j-1,l+1,board,word);
        
           if(!k && i+1<mm && !vis[i+1][j] && board[i+1][j]==word[l])
               k=check(i+1,j,l+1,board,word);
        
           if(!k && j+1<mn && !vis[i][j+1] && board[i][j+1]==word[l])
               k=check(i,j+1,l+1,board,word);
        
            vis[i][j]=0;
        
           return k;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        mn=n;
        mm=m;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(word[0]==board[i][j] && check(i,j,1,board,word))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};