class Solution {
public:
    bool valid(stack<char>&st,char c)
    {
        if(!st.empty())
        {
            if(st.top()=='(' && c==')')
                return true;
            if(st.top()=='{' && c=='}')
                return true;
            if(st.top()=='[' && c==']')
                return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for( char c:s )
        {
             if(c=='(' ||c=='{'|| c=='[')
                 st.push(c);
            else if(valid(st,c))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};