class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int j=0;
        for(char c:strs[0])
        {
            bool l=true;
            for(int k=1;k<strs.size();k++)
            {
               if(c!=strs[k][j])
               {
                   l=false;
                   break;
               }
            }
            
            if(l)
                ans+=c;
            else 
                break;
            
            j++;
        }
        return ans;
    }
};