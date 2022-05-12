class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int>res;
        
        if(n==1)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        res=grayCode(n-1);
        int mx=pow(2,n-1);
        
        for(int i=res.size()-1;i>=0;i--)
        {
           res.push_back(mx+res[i]);            
        }
        
        return res;
    }
};