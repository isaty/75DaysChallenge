class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>res;
        int left=-1,right=-1;
        int l=0,r=nums.size()-1;
        
        //shifting left
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                left=mid;
                r=mid-1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        l=0,r=nums.size()-1;
        //shifting right
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                right=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};