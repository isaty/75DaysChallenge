class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int>res(nums.size(),0);
        stack<int>left;
        stack<int>right;
        int n=nums.size()-1;
        
        for(int i=n;i>=0;i--)
        {
            left.push(nums[i]);    
        }
        
        for(int i=n;i>=0;i--)
        {
            while(!right.empty() && nums[i]>=right.top())
                right.pop();
            
            if(right.empty())
            {
                while(!left.empty() && nums[i]>=left.top())
                    left.pop();
                
                if(left.empty())
                    res[i]=-1;
                else 
                    res[i]=left.top();
            }
            else
            {
               res[i]=right.top();    
            }
            
            right.push(nums[i]);
        }
        
        return res;
        
    }
};