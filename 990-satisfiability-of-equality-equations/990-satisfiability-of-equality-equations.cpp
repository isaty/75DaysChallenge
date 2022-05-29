class Solution {
public:
    int parent[26];
    int size[26];
    
    char find(int a)
    {
        if(parent[a]<0)
            return a;
        return find(parent[a]);
    }
    
    void unionbysize(int a,int b)
    {
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
    static bool comp(const string &a,const string &b)
    {
        return (a[1]=='=' && b[1]=='!');
    }
    bool equationsPossible(vector<string>& equations) {
        
        sort(equations.begin(),equations.end(),comp);
        for(int i=0;i<26;i++)
        {
          parent[i]=-1;
          size[i]=0;
        }
        
        for(string i:equations)
        {
            // cout<<i<<"\n";
            int a=i[0]-'a';
            int b=i[3]-'a';
            char c=i[1];
            
            int a_par=find(a);
            int b_par=find(b);
            
            if(a_par!=b_par && c=='=')
            {
                unionbysize(a_par,b_par);
            }
            else if(a_par==b_par && c== '!')
            {
                return false;
            }
                
        }
        
        return true;
    }
};