class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>out,vector<int>&nums,int i,int target)
    {
        // cout<<target<<"\n";
        if(target==0)
        {
            res.push_back(out);
            return;
        }
        
        if(i>=nums.size())
            return;
        
        for(int j=i;j<nums.size();j++)
        {
            if(target>=nums[j])
            {
                // cout<<target-nums[j]<<"\n";
                out.push_back(nums[j]);
                dfs(out,nums,j,target-nums[j]);
                out.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>out;
        sort(candidates.begin(),candidates.end());  
        dfs(out,candidates,0,target);
        return res;
    }
};