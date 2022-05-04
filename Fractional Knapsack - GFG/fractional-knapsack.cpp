// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item &a,Item &b)
    {
        double valbyweight1=(double)a.value/(double)a.weight;
        double valbyweight2=(double)b.value/(double)b.weight;
        return valbyweight1 >= valbyweight2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double ans=0.0;
        int i=0,cap=0;
        while(i<n && cap<W)
        {
            if(arr[i].weight<=(W-cap))
            {
                ans+=arr[i].value;
                cap+=arr[i].weight;
            }
            else
            {
               double diff=W-cap;
               double fract=diff/(double)arr[i].weight;
               ans+=arr[i].value*fract;
               cap=W;
            }
            i++;
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends