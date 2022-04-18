class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>dq;
        vector<int>res;
        
        int i=0,j=0;
        while(j<nums.size())
        {
            if(j-i==k)
            { 
               res.push_back(nums[dq.front()]);
               if(dq.front()==j-k)
               {
                   dq.pop_front();
               }
               i++;
            }
            
            while(!dq.empty() && nums[dq.back()]<nums[j])
                dq.pop_back();
            
            dq.push_back(j);
            j++;
        }
        
        res.push_back(nums[dq.front()]);
        return res;
    }
};