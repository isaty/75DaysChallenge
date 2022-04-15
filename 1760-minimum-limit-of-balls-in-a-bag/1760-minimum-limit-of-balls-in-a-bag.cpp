class Solution {
public:
    int operations(vector<int>& nums,int mx)
    {
        int cnt=0;
        for(int i:nums)
        {
            if(i>mx)
            {
                if(i%mx==0)
                cnt+=(i/mx)-1;
                else
                cnt+=i/mx;    
            }
        }
        return cnt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
    
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=0;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int opr=operations(nums,mid);
            // cout<<mid<<" "<<opr<<"\n";
            if(opr<=maxOperations)
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