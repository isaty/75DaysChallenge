class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int str=nums.size(),cur=0;
        while(cur<str)
        {
            if(nums[cur]==0)
            {
                int j=cur;
                while(j<str-1)
                {
                    swap(nums[j+1],nums[j]);
                    j++;
                }
                cur--;
                str--;
            }
            cur++;
        }
        
    }
};