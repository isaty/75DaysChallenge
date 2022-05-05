// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job &a,Job &b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int mx=0;
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++)
        {
            if(mx<arr[i].dead)
               mx=arr[i].dead;
        }
        
        int cnt=0,profit=0;
        vector<int>job_window(mx,-1);
        
        for(int i=0;i<n;i++)
        {
            int deadline=arr[i].dead;
            for(int j=deadline-1;j>=0;j--)
            {
                if(job_window[j]==-1)
                {
                    cnt++;
                    job_window[j]=i;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int>res;
        res.push_back(cnt);
        res.push_back(profit);
        
        return res;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends