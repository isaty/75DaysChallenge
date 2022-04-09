class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
       int anchr=0,sum=0,ans=INT_MAX;
        
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           while(sum>=target)
           {
               ans=min(ans,i-anchr+1);
               sum-=nums[anchr];
               anchr++;
           }
       }
        return ans==INT_MAX? 0:ans;
    }
};