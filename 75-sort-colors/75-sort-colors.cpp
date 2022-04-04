class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int i=0;
        while(i<=r)
        {
            if(nums[i]==0)
            {
                // cout<<i<<" "<<l<<"\n";
                swap(nums[i],nums[l]);
                l++;
            }
            else if(nums[i]==2)
            {
                // cout<<i<<" "<<r<<"\n";
                swap(nums[i],nums[r]);
                r--;
                i--;
            }
            // for(int i:nums)
            //     cout<<i<<" ";
            // cout<<"\n";
            i++;
        }
        
    }
};