class Solution {
public:
    int characterReplacement(string s, int k) {
      
        unordered_map<char,int>mp;
        int anchr=0,maxChar=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            maxChar=max(maxChar,mp[s[i]]);
            
            // int distinctChar=i-anchr-maxChar+1;
            if(k < i-anchr-maxChar+1)
            {
                mp[s[anchr]]--;
                anchr++;
            }
            ans=max(ans,i-anchr+1);
        }
        return ans;
        
    }
};