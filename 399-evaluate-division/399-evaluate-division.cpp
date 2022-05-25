class Solution {
public:
    unordered_map<string,unordered_map<string,double>>adj;
    double dfs(string cur,string des,unordered_set<string>&vis)
    {
        if(cur==des)
        {
            return 1.0000;
        }
        
        vis.insert(cur);
        
        for(auto i:adj[cur])
        {
            if(vis.find(i.first)==vis.end())
            {
               double ans=dfs(i.first,des,vis); 
               if(ans>0)
               {
                   return ans*i.second;
               }
            }
        }
        
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>res;
        for(int i=0;i<equations.size();i++)
        {
            string a=equations[i][0];
            string b=equations[i][1];
            adj[a][b]=values[i];
            adj[b][a]=1.00000/values[i];
        }
        
        for(auto i:queries)
        {
            unordered_set<string>vis;
            double ans=-1;
            
            if(adj.find(i[0])!=adj.end() && adj.find(i[1])!=adj.end())
            ans=dfs(i[0],i[1],vis);
            
            res.push_back(ans);
        }
        return res;
    }
};