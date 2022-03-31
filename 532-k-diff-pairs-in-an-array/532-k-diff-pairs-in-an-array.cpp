class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            
            int l=i+1,r=nums.size()-1;
            int t=nums[i]+k;
            
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]==t)
                {
                    ans++;
                    break;
                }
                else if(nums[mid]>t)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};