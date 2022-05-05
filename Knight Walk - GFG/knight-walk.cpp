// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    
    int dx[8]={-2,-1, -2,-1, 2,1,  2,1};
    int dy[8]={-1,-2, 1,2,   1,2,  -1,-2};
	
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    int movs=0;
	    
	    while(!q.empty())
	    {
	        int k=q.size();
	        while(k--)
	        {
    	        pair<int,int>p=q.front();
    	        q.pop();
	            
	            if(p.first==TargetPos[0] && p.second==TargetPos[1])
	                return movs;
	        
    	        for(int i=0;i<8;i++)
    	        {
    	            int x=p.first+dx[i];
    	            int y=p.second+dy[i];
    	            
    	            if(x>0 && y>0 && x<=N && y<=N &&!vis[x][y])
    	            {
    	                q.push({x,y});
    	                vis[x][y]=1;
    	            }
    	        }
	            
	        }
	        movs++;
	    } 
	    return movs;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends