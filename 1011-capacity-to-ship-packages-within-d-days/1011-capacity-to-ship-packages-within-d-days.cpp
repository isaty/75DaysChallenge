class Solution {
public:
    int capacity(vector<int>& weights,int cap)
    {
        int cnt=0,sum=0;
        
        for(int i:weights)
        {
            if(sum+i>cap)
            {
                sum=i;
                cnt++;
            }
            else
            {
                sum+=i;
            }
        }
        return cnt+1;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end()),r=0;
        
        for(int i:weights)
        {
          r+=i;   
        }
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int rday=capacity(weights,mid);
            // cout<<mid<<" "<<rday<<"\n";
            if(rday<=days)
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