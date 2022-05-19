// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	int par[1001],size[1001];
	int find(int a)
	{
	    if(par[a]<0)
	     return a;
	     
	    return find(par[a]); 
	}
	
	void unionbyrank(int a,int b)
	{
	    if(size[a]>size[b])
	    {
	        par[a]=b;
	        size[b]+=size[a];
	    }
	    else
	    {
	        par[b]=a;
	        size[a]+=size[b];
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int cost=0;
        vector<vector<int>>edges;
        
        for(int i=0;i<V;i++)
        {
            par[i]=-1;
            size[i]=0;
            
            for(vector<int>j:adj[i])
            {
                edges.push_back({j[1],i,j[0]});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        for(vector<int>i:edges)
        {
            int wt=i[0];
            int a=i[1];
            int b=i[2];
            
            int par_a=find(a),par_b=find(b);
            if(par_a!=par_b)
            {
                cost+=wt;
                unionbyrank(par_a,par_b);
            }
        }
        
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends