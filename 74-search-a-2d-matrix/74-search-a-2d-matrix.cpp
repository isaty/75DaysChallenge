class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        
        int n=nums.size()-1,m=nums[0].size()-1;
        
        //find the row
        int rw=-1,l=0,r=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target>=nums[mid][0] && target<=nums[mid][m])
            {
                rw=mid;
                break;
            }
            else if(target<nums[mid][0])
            {
                r=mid-1;
            }
            else if(target>nums[mid][m])
            {
                l=mid+1;
            }
        }
        
        if(rw==-1)
            return false;
        
        l=0,r=m;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target==nums[rw][mid] )
            {
                rw=mid;
                return true;
            }
            else if(target<nums[rw][mid])
            {
                r=mid-1;
            }
            else if(target>nums[rw][mid])
            {
                l=mid+1;
            }
        }
        
        return false;
    }
};