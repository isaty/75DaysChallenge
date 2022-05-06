class Solution {
public:
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void dfs(string &in,string out,int i,int n)
    {
        if(i>=n)
        {
            if(out.length()>0)
            ans.push_back(out);
            return;
        }
       
        int p=in[i]-'0';
        for(int j=0;j<arr[p].size();j++)
        {
            out.push_back(arr[p][j]);
            dfs(in,out,i+1,n);
            out.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // cout<<stoi(digits[0]);
        dfs(digits,"",0,digits.length());
        return ans;
    }
};