class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int curr=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(i>0 && i+1<prices.size() && prices[i-1]<=prices[i] && prices[i]>prices[i+1])
            {
                ans+=prices[i]-curr;
                curr=prices[i+1];
            }
            else if(i>0 && i==prices.size()-1 && prices[i-1]<=prices[i] )
            {
                ans+=prices[i]-curr;
            }
            else
            {
                curr=min(curr,prices[i]);
            }
        }
        return ans;
    }
};