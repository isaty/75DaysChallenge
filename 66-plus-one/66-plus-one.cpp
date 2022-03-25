class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
       int c=1;
        vector<int>res;
       for(int i=digits.size()-1;i>=0;i--)
       {
           int m=digits[i]+c;
           c=m/10;
           m=m%10;
           res.push_back(m);
       }
       
        if(c>=1)
           res.push_back(c);
       
        reverse(res.begin(),res.end());
       return res; 
        
    }
};