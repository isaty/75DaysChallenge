class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        set<int>st1;
        set<int>st2;
        
        int mod=1e9+7;
        
        st1.insert(h);
        st2.insert(w);
        
        for(int i:horizontalCuts)
        {
            st1.insert(i);
        }
        
        for(int i:verticalCuts)
        {
            st2.insert(i);
        }
        
        long long int mh=0;
        int prev=0;
        for(auto i:st1)
        {
            if(mh < i-prev)
                mh=i-prev;
            prev=i;
        }
        
        prev=0;
        long long int mv=0;
        for(auto i:st2)
        {
            if(mv < i-prev)
                mv=i-prev;
            prev=i;
        }
        long long int ans=(mv%mod) * (mh%mod);
        return ans%mod;
    }
    
};