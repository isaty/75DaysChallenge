class Solution {
public:
    vector<vector<int>>res;
    void dfs(int i,vector<int>out,vector<int>& nums)
    {
        res.push_back(out);
        
        if(i>=nums.size())
        {
            return;
        }
        
        for(int j=i;j<nums.size();j++)
        {
                out.push_back(nums[j]);
                dfs(j+1,out,nums);
                out.pop_back();   
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>out;
        dfs(0,out,nums);
        return res;
    }
};