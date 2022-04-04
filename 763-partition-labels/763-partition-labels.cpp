class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>al(26,-1);
        vector<int>res;
        
        for(int i=0;i<s.length();i++)
        {
            al[s[i]-'a']=i;
        }
        
        int anch1=0,anch2=0;
        
        for(int i=0;i<s.length();i++)
        {
            anch2=max(anch2,al[s[i]-'a']);
            
            if(anch2==i)
            {
                res.push_back(anch2-anch1+1);
                anch1=i+1;
            }        
        }
        return res;
    }
};