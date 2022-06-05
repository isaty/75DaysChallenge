class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int j=0;
        for(char c:strs[0])
        {
            for(int k=1;k<strs.size();k++)
            {
               if(c!=strs[k][j])
               {
                   return ans;
               }
            } 
           ans+=c;
           j++;
        }
        return ans;
    }
};