class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mod=1e9+7;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i-1]==nums[i])continue; 

            for(int j=i+1;j<=n-3;j++)
            {
                if(j>i+1 && nums[j-1]==nums[j])continue;
                
                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    int t=(((nums[i]+nums[j])%mod+nums[l])%mod+nums[r])%mod;
                    if(t==target)
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        
                        while(l<r && nums[l]==nums[l+1])
                        {
                            l++;
                        }
                        l++;
                        
                        while(r>l && nums[r]==nums[r-1])
                        {
                            r--;
                        }
                        r--;
                    }
                    else if(t>target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};