class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.length() > haystack.length())
            return -1;
        
        int k=needle.length();        
        for(int i=0;i<=haystack.length()-k;i++)
        {
            string s=haystack.substr(i,k);
            // cout<<s<<"\n";
            if(s==needle)
            {
                return i;
            }
        }
        return -1;
    }
};