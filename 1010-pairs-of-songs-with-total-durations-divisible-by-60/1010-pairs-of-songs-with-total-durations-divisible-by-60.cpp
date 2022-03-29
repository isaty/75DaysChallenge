class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int,unordered_set<int>>mp;
        
        int arr[17]={60,120,180,240,300,360,420,480,540,600,660,720,780,840,900,960,1020};
        int cnt=0;
        
        for(int i=0;i<time.size();i++)
        {
            mp[time[i]].insert(i);
        }
        
        for(int i=0;i<time.size();i++)
        {
            if(mp[time[i]].find(i)!=mp[time[i]].end())
                 mp[time[i]].erase(i);
            
            for(int j=0;j<17;j++)
            {
                int t=arr[j]-time[i];
                // cout<<t;
                if(mp.find(t)!=mp.end())
                {
                    cnt+=mp[t].size();
                }
            }
            
        }
        return cnt;
    }
};