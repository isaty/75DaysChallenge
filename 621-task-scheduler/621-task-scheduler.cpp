class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int ans=0;
        for(char c:tasks)
            mp[c]++;
        
        for(auto i:mp)
            pq.push(i.second);
        
        while(!pq.empty())
        {
            vector<int>tmp;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            
            for(int i:tmp)
            {
                if(i>0)
                    pq.push(i);
            }
            
            ans+=pq.empty()? tmp.size():n+1;
        }
        return ans;
    }
};