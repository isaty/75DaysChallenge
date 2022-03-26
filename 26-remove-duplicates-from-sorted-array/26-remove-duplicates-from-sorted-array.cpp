class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int prev=nums[0];
        int i=1,k=1;
        while(i<nums.size())
        {
            if(nums[i]!=prev)
            {
                nums[k]=nums[i];
                prev=nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};