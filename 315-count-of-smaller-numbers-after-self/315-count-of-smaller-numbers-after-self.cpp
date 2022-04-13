class Solution {
public:
    
    //count inversion template
    void merge(vector<pair<int,int>>&ar,int l,int m,int r,vector<int>&cnt)
    {
        int t1=m-l+1;
        int t2=r-m;
        vector<pair<int,int>>a1,a2;
        
        for(int i=0;i<t1;i++)
            a1.push_back(ar[i+l]);
        for(int i=0;i<t2;i++)
            a2.push_back(ar[m+i+1]);
        
        int i=0,j=0,k=l,c=0;
        while(i<t1 && j<t2)
        {
            if(a2[j].first>=a1[i].first)
            {
                ar[k++]=a2[j++];
            }
            else
            {
                cnt[a1[i].second]+=t2-j;
                ar[k++]=a1[i++];
            }
        }
             
        while(i<t1)
        {
            ar[k++]=a1[i++];
        }
        
        while(j<t2)
        {
            ar[k++]=a2[j++];
        }
    }
    
    void mergesort(vector<pair<int,int>>&ar,int l,int r,vector<int>&cnt)
    {
        if(l>=r)
            return;
        int m=l+(r-l)/2;
        mergesort(ar,l,m,cnt);
        mergesort(ar,m+1,r,cnt);
        merge(ar,l,m,r,cnt);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        
        //pair of (num,index).
        vector<pair<int,int>>ar;
        
        vector<int>cnt(n,0);
        for(int i=0;i<nums.size();i++)
        {
            ar.push_back({nums[i],i});
        }
        
        //mergesort
        mergesort(ar,0,n-1,cnt);
        
        return cnt;
    }
};