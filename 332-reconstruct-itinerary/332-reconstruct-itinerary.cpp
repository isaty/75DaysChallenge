class Solution {
public:
    
    map<string,set<string>>adj;
    vector<string>res;

    bool dfs(string cur,int edges,vector<string>out,unordered_map<string,int>edg)
    {
        out.push_back(cur);
        
        if(edges==0)
        {
            res=out;
            return true;
        }
        
        for(auto i:adj[cur])
        {
          string e=cur+"."+i;
        
          if(edg[e]>0)
          {
              
              edg[e]--;
              
              if(dfs(i,edges-1,out,edg))
              return true;
             
              edg[e]++;
          }
        }
        
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    
        int edges=tickets.size();
        unordered_map<string,int>edg;
        for(vector<string>i:tickets)
        {
            adj[i[0]].insert(i[1]);
            string edge=i[0]+"."+i[1];
            edg[edge]++;
        }
        
        vector<string>out;
        dfs("JFK",edges,out,edg);
        return res;
    }
};