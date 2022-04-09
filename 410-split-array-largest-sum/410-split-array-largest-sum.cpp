class Solution {
public:
    
    int parts(vector<int>& nums,int maxsum)
    {
        int cnt=0,sum=0;
        for(int i:nums)
        {
            if(sum+i>maxsum)
            {
                cnt++;
                sum=i;
            }
            else
            {
                sum+=i;
            }
        }
        // cout<<cnt<<" ";
        return cnt+1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int l=*max_element(nums.begin(),nums.end()),r=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
           int partitions=parts(nums,mid);
           // cout<<mid<<" "<<partitions<<"\n";
            if(partitions<=m)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
    
};