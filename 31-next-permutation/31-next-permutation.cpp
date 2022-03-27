class Solution {
public:
    void nextPermutation(vector<int>& nums) {
          int n=nums.size();
          int p=-1;
          //start from the rightmost side and find the first non increasing element
          for(int i=n-2;i>=0;i--)
          {
              if(nums[i]<nums[i+1])
              {
                  p=i;
                  break;
              }
          }
        
        if(p==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>=0;i--)
        {
           if(nums[p]<nums[i])
           {
               swap(nums[i],nums[p]);
               break;
           }
        }
        reverse(nums.begin()+p+1,nums.end());
        
    }
}; 