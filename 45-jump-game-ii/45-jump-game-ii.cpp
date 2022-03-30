class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int c=0;
        int mx=0;
        int k=0;
        for(int i=0;i<n-1;i++)
        {
            mx=max(mx,i+nums[i]);
            if(i==k)
            {
                c++;
                k=mx;
            }
                
        }
        
        return c;
    }
};