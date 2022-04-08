class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        
        int l=0,r=n;
        double ans;
        
        while(l<=r)
        {
            int c1=l+(r-l)/2;
            int c2=(n+m+1)/2-c1;
            
            int n1= c1==0? INT_MIN:nums1[c1-1];
            int n2= c2==0? INT_MIN:nums2[c2-1];
            
            int n3= c1==n? INT_MAX:nums1[c1];
            int n4= c2==m? INT_MAX:nums2[c2];
            
            if(n1<=n4 && n2<=n3)
            {
                 if((n+m)%2==0)
                 {
                      ans=(max(n1,n2)+min(n3,n4))/2.0;
                 }
                 else
                 {
                      ans=max(n1,n2);
                 }
                break;
            }
            else if(n1>n4)
            {
                r=c1-1;
            }
            else
            {
                l=c1+1;
            }
        }
        return ans;
    }
};