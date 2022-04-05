class Solution {
public:
    int atmostk(vector<int>& nums, int k)
    {
        unordered_map<int,int>mp;
        int i=0,anchr=0,num=0;
        while(i<nums.size())
        {
            mp[nums[i]]++;
            
            while(mp.size()>k)
            {
                mp[nums[anchr]]--;
                
                if(mp[nums[anchr]]==0)
                    mp.erase(nums[anchr]);
                
                anchr++;
            }
            num+=i-anchr+1;
            
            i++;
        }
        
        return num;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmostk(nums,k)-atmostk(nums,k-1);    
    }
};