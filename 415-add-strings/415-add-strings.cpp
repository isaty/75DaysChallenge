class Solution {
public:
    string addStrings(string num1, string num2) {
        int c=0;
        int i=num1.length()-1,j=num2.length()-1;
        string ans="";
        while(i>=0 && j>=0)
        {
            int a=num1[i--]-'0';
            int b=num2[j--]-'0';    
            int sum=a+b+c;
            c=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        
        while(i>=0)
        {
            int a=num1[i--]-'0';
            int sum=a+c;
            c=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        
        while(j>=0)
        {
            int b=num2[j--]-'0';
            int sum=b+c;
            c=sum/10;
            sum=sum%10;
            ans+=to_string(sum);
        }
        
        if(c>0)
        {
            ans+=to_string(1);
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};