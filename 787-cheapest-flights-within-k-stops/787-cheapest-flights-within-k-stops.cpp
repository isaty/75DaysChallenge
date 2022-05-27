class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>prices(n,1e8);
        prices[src]=0;
        
        for(int i=0;i<=k;i++)
        {
            vector<int>temp=prices;
            for(vector<int>e:flights)
            {
                if(prices[e[0]]+e[2] < temp[e[1]])
                    temp[e[1]]=prices[e[0]]+e[2];
            }
            prices=temp;
        }
        
        return prices[dst]!=1e8? prices[dst]:-1;
    }
};