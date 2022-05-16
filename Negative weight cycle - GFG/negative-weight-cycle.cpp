// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dis(n,1000006);
	    dis[0]=0;
	    for(int i=1;i<n;i++)
	    {
	        for(auto j:edges)
	        {
	            if(dis[j[0]]+j[2] < dis[j[1]])
	            {
	               dis[j[1]]=dis[j[0]]+j[2]; 
	            }
	        }
	    }
	    
	    for(vector<int>i:edges)
	    {
	        if(dis[i[0]]+i[2] < dis[i[1]])
	        return 1;
	    }
	    
	    return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends