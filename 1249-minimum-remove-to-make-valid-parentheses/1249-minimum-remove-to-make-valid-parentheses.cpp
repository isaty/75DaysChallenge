class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        unordered_set<int>hsh;
        for(int i=0;i<s.length();i++)
        {

            if(s[i]==')' && !st.empty() && st.top().first=='(')
            {
                hsh.erase(st.top().second);
                st.pop();
                continue;
            }
            else if(s[i]=='(' || s[i]==')')
            {
               st.push({s[i],i});
               hsh.insert(i);    
            }
            
        }
        
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(hsh.find(i)==hsh.end())
                ans+=s[i];
        }
        return ans;
    }
};