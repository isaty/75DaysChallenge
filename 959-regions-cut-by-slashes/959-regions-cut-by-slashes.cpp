class Solution {
public:
    
    int parent[1000];
    int size[1000];
    int cnt;
    int find(int a)
    {
        if(parent[a]<0)
            return a;
        return find(parent[a]);
    }
    
    void unionbysize(int a,int b)
    {
        a=find(a);
        b=find(b);
        
        if(a==b)
        {
           cnt++;
           return; 
        } 
        
       if(size[a]>size[b])
       {
          parent[a]=b;
          size[b]+=size[a]; 
       }
       else
       {
          parent[b]=a;
          size[a]+=size[b];
       }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        n=n+1;
        
        
        for(int i=0;i<n*n;i++)
        {
            parent[i]=-1;
            size[i]=0;
        }
        
        //
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==n-1)
                {
                    //union with 0
                    int cell=i*n+j;
                    unionbysize(0,cell);
                }
            }
        }
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(grid[i][j]=='/')
                {
                    int a=i*n+j+1 ;
                    int b=(i+1)*n+j;
                    unionbysize(a,b);
                }
                else if(grid[i][j]=='\\')
                {
                    int a=i*n+j ;
                    int b=(i+1)*n+(j+1);
                    unionbysize(a,b);
                }
            }
        }
        
        return cnt;
    }
};