class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //WRONG IMPLEMENTATION | QUESTION ASKS FOR INTEGER ENVIRONMENT
        if(dividend==INT_MIN && divisor==-1)
        {
            return INT_MAX;
        }
        int sign=((dividend>0) ^ (divisor>0))? -1:1;
        long dvd=abs(dividend);
        long dvs=abs(divisor);
        long ans=0;
        while(dvd>=dvs)
        {
            long temp=dvs,m=1;   
            while((temp<<1) <= dvd)
            {
                temp=temp<<1;
                m=m<<1;
            }
            dvd=dvd-temp;
            ans=ans+m;
        }
        return ans*sign;
    }
};