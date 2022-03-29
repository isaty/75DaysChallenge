class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans=1002;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int t=nums[i]+nums[l]+nums[r];
            // cout<<t<<"\n";
            
            if(abs(target-t) < abs(target-ans))
                ans=t;
            
            if(target==t)
            {
                // cout<<t;
                return t;
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
        
        return ans;
    }
};