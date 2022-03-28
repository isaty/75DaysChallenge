class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        for(int i=0;i<=n/2;i++)
        {
             
             int a=i,b=i;
            
             //upper row
             while(b<m-i)
             {
                  res.push_back(matrix[a][b]);
                 b++;
                 cnt++;
             }
            if(cnt==(n*m))
                break;
             
              
             //rightmost column
             a++;
             b=m-i-1;
             while(a<n-i)
             {
                res.push_back(matrix[a][b]);
                a++; 
                 cnt++;
             }
            if(cnt==(n*m))
                break;
        
        
             //lower row
             a=n-i-1;
             b--;
             while(b>=i)
             {
                 res.push_back(matrix[a][b]);
                 b--;
                 cnt++;
             }
            if(cnt==(n*m))
                break;
          
            
             //leftmost column
             b=i;
             a--;
             while(a>i)
             {
                 res.push_back(matrix[a][b]);
                 a--;
                 cnt++;
             }
            if(cnt==(n*m))
                break;
    
        }
        return res;
    }
};