class Solution {
public:
    
    double helper(double x, int n)
    {
         if(n==0)
            return 1;
        
        double k=helper(x,n/2);
        k=k*k;
        
        if(n%2==0)
            return k;
        
        return k*x;
    }
    
    double myPow(double x, int n) {
         double ans=helper(x,abs(n));
         // cout<<ans<<" ";
        if(n<0)
            return double(1/ans);
        
        return ans;
    }
};