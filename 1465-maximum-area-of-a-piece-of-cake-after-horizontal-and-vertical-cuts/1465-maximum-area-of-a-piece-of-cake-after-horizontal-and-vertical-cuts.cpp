class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod=1e9+7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        long long int mh=0;
        int prev=0;
        for(int i:horizontalCuts)
        {
            if(mh < i-prev)
                mh=i-prev;
            prev=i;
        }
        
        prev=0;
        long long int mv=0;
        for(auto i:verticalCuts)
        {
            if(mv < i-prev)
                mv=i-prev;
            prev=i;
        }
        long long int ans=(mv%mod) * (mh%mod);
        return ans%mod;
    }
    
};