class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int>al(26,-1);
        for(int i=0;i<order.length();i++)
        {
            al[order[i]-'a']=i;
        }
        
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                
                //checking sequentially
                int l=0,r=0;
                bool isEqual=true;
                while(l<words[i].length() && r<words[j].length())
                {
                    int a=al[words[i][l]-'a'];
                    int b=al[words[j][r]-'a'];
                    // cout<<words[i][l]<<" "<<a<<" "<<words[j][r]<<" "<<b<<"\n";
                    if(a>b)
                        return false;
                    
                    if(a<b)
                    {
                        isEqual=false;
                        break;
                    }
                    
                    l++;
                    r++;
                }
                
                if(isEqual && words[i].length()>words[j].length())
                    return false;
            }
        }
        
        return true;
    }
};