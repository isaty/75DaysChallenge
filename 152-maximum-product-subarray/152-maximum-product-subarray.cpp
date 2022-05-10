class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
        int mx_neg=nums[0],mx_pos=nums[0];
        int glb=nums[0];
        for(int i=1;i<nums.size();i++)
        {
                if(nums[i]<0)
                    swap(mx_pos,mx_neg);
                
                mx_pos=max(mx_pos*nums[i],nums[i]);
                mx_neg=min(mx_neg*nums[i],nums[i]);
                glb=max(glb,mx_pos);
        }
        
        return glb;
    }
};