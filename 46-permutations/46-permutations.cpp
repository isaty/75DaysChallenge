class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>out,int i)
    {
       
        if(i>=out.size())
        {   
            res.push_back(out);
            return;
        }
        
        for(int j=i;j<out.size();j++)
        {
            swap(out[j],out[i]);
            dfs(out,i+1);
            swap(out[j],out[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
};