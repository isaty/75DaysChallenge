class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        vector<int>res;
        map<int,int,greater<int>>mp;
        
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        
        auto j=mp.begin();
        pair<int,int>p=*j;
        res.push_back(p.first);
        
        for(int i=k;i<nums.size();i++)
        {
            mp[nums[i-k]]--;
            
            if(mp[nums[i-k]]==0)
            {
                // cout<<mp.size();
                mp.erase(nums[i-k]);}
            
            
            
            mp[nums[i]]++;
            auto k=mp.begin();
            pair<int,int>l=*k;
            res.push_back(l.first);
        }
        
        return res;
    }
};