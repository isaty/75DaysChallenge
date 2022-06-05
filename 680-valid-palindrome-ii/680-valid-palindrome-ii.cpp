class Solution {
public:
    
    bool valid(string& s, int i,int n)
    {
        while(i<n)
        {
            if(s[i]!=s[n])
                return false;
            i++;
            n--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,n=s.length()-1;
        while(i<n)
        {
            if(s[i]!=s[n])
            {
                return valid(s,i,n-1)||valid(s,i+1,n);
            }
            i++;
            n--;
        }
        return true;
    }
};