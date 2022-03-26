class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[l]+nums[r]+nums[i];
                
                if(sum==0)
                {
                    res.push_back({nums[l],nums[r],nums[i]});
                    
                    //skip to avoid duplicacy
                       while(l<r && nums[l]==nums[l+1])
                       {
                           l++;
                       }
                       l++;
                    
                    //skip to avoid duplicacy
                    while(r>l && nums[r]==nums[r-1])
                    {
                        r--;
                    }
                    
                }
                else if(sum<0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return res;
        
    }
};