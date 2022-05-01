class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int>res;
        
        unordered_map<int,int>cnt;
        
        for(int i:nums)
            cnt[i]++;
        
        priority_queue<pair<int,int>>pq;
        
        for(auto i:cnt)
            pq.push({i.second,i.first});
        
        int i=0;
        
        while(i<k && !pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return res;
    }
};