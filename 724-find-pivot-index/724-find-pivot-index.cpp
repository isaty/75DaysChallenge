class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0,rightsum=0;
        for(int i:nums)
        {
            rightsum+=i;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(leftsum==rightsum-nums[i])
            {
                return i;
                break;
            }
            leftsum+=nums[i];
            rightsum-=nums[i];
        }
        return -1;
    }
};