class Solution {
public:
    void  palindrome(string &s,int &l,int &r)
    {
        while(l>=0 && r<s.length())
        {
            if(s[l]!=s[r])
            {
                return ;
            }
            l--;
            r++;
        }
        return ;
    }
    
    string longestPalindrome(string s) {
           string ans="";
           int mx=0;
        
           for(int i=0;i<s.length();i++)
           {
               //even
               int l1=i;
               int r1=i+1;
               palindrome(s,l1,r1);
               int s1=(r1-l1+1)-2;
               
               //odd
               int l2=i-1;
               int r2=i+1;
               palindrome(s,l2,r2);
               int s2=(r2-l2+1)-2;
               
               
                if(s1>mx)
                {
                   ans=s.substr(l1+1,s1);
                   mx=s1;
                }
                else if(s2>mx)
                {
                   ans=s.substr(l2+1,s2);
                   mx=s2;
                }
               
           }
        
        return ans;
    }
};