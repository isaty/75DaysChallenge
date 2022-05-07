class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>out,vector<int>& nums,int i,int n,int target)
    {
            if(target==0)
            {
               res.push_back(out);
               return;
            }
         
           if(i>=n)
               return;
        
           for(int j=i;j<n;j++)
           {
                   if(j>i && nums[j]==nums[j-1])continue;
                  if(target>=nums[j])
                  {
                      out.push_back(nums[j]);
                      dfs(out,nums,j+1,n,target-nums[j]);
                      out.pop_back();
                  }
                  
           }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>out;
        sort(candidates.begin(),candidates.end());
        dfs(out,candidates,0,candidates.size(),target);
        return res;
    }
};