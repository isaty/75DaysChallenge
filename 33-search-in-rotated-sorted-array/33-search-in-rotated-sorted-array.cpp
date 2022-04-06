class Solution {
public:
    int pivot(vector<int>& nums)
    { 
        int p=0,l=0,r=nums.size()-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mid>0 && nums[mid-1]>nums[mid])
            {
                p=mid;
                break;
            }
            else if(nums[mid]<nums[r])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return p;
    }
    
    int find(vector<int>& nums, int target,int l ,int r)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
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
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int p=pivot(nums);
        
        if(p==0)
        {
            return find(nums, target, 0,nums.size()-1);
        }
        
        int l=find(nums,target,0,p-1);
        if(l!=-1)
            return l;
        
        return find(nums,target,p,nums.size()-1);
        
    }
};