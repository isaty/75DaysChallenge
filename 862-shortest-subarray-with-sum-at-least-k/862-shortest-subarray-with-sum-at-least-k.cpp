class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n=nums.size(),res=INT_MAX;
        deque<int>dq;
        long  prefix[n+1];
        prefix[0]=0;
        // cout<<prefix[0]<<" ";
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
            // cout<<prefix[i+1]<<" ";
        }
        // cout<<"\n";
        
        for(int i=0;i<n+1;i++)
        {
            // if()
            while(dq.size()>0 && prefix[i]-prefix[dq.front()]>=k)
            {
                res=min(res,i-dq.front());
                dq.pop_front();
                // cout<<"res "<<res<<" ";
            }
            // cout<<"\n";
            while(dq.size()>0 && prefix[i]<=prefix[dq.back()])
            {
                // cout<<"last "<<dq.back()<<" ";
                dq.pop_back();
            }
            // cout<<"\n";
            
            dq.push_back(i);
        }
        // cout<<res<<"\n";
        return res==INT_MAX? -1:res;
    }
};