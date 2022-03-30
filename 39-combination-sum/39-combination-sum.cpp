class Solution {
public:
    vector<vector<int>>res;
    void recursion(int i, int target,vector<int>& candidates,vector<int>out)
    {
        if(target==0)
        {
            res.push_back(out);
            return;
        }
        
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]<=target)
            {
                out.push_back(candidates[j]);
                recursion(j,target-candidates[j],candidates,out);
                out.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>out;
        recursion(0,target,candidates,out);
        return res;
    }
};