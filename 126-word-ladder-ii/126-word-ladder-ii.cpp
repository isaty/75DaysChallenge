class Solution {
public:
    unordered_map<string,vector<string>>adj;
    unordered_set<string>st;
    vector<vector<string>>res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<string>ans;
        unordered_set<string>vis;
      
        for(string i:wordList)
        {
            st.insert(i);
        }
        
        if(st.find(endWord)==st.end())
            return res;
        
        if(st.find(beginWord)==st.end())
            st.insert(beginWord);    
        
        for(auto i:st)
        {
            string s=i;
            for(int k=0;k<s.length();k++)
            {
                for(int j=0;j<26;j++)
                {
                       s[k]='a'+j;
                       if(s[k]!=i[k] && st.find(s)!=st.end())
                       {
                           adj[i].push_back(s);
                       }
                }
                s[k]=i[k];
            }
        }
        
        queue<vector<string>>q;
        q.push({beginWord});
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                vector<string>t=q.front();
                q.pop();
                
                string u=t.back();
                
                if(u==endWord)
                {
                    res.push_back(t);
                    continue;
                }
                
                vis.insert(u);
                
                for(string s:adj[u])
                {
                    if(vis.find(s)!=vis.end())
                    continue;
                    
                    t.push_back(s);
                    q.push({t});
                    t.pop_back();
                }   
            }
            if(res.size()>0)
                break;
        }
        
        return res;

    }
};