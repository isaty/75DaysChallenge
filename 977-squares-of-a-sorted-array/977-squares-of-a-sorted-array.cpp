class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int a=r+1;
        vector<int>res;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==0)
            {
                a=mid;
                break;
            }
            else if(nums[mid]>0)
            {
                a=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    
        l=-1,r=nums.size();
        if(a<nums.size() && nums[a]==0)
        {
            l=a-1;
            r=a;
        }
        else if(a<nums.size() && nums[a]>0 || a==0)
        {
            l=a-1;
            r=a;
        }
        else if(a==nums.size())
        {
            l=a-1;
            r=a;
        }
        
        while(l>=0 && r<nums.size())
        {
            if(abs(nums[l])<=nums[r])
            {
                res.push_back(nums[l]*nums[l]);
                l--;
            }
            else
            {
                res.push_back(nums[r]*nums[r]);
                r++;
            }
            
        }
        
        while(l>=0)
        {
            res.push_back(nums[l]*nums[l]);
            l--;
        }
        
        while(r<nums.size())
        {
            res.push_back(nums[r]*nums[r]);
            r++;
        }
          
        return res;
    }
};