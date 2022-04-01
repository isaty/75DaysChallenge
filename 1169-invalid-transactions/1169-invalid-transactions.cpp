class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>res;
        
        unordered_set<int>st;
        int n=transactions.size();
        vector<string>name;
        vector<string>city;
        vector<int>time;
        vector<int>amount;
        
        for(string i:transactions)
        {
           int j=0;
            
           //name
            string nme=""; 
            while(j<i.length() && i[j]!=',')
            {
                nme+=i[j];
                j++;
            }
            j++;
            
           //time
            int t=0;
            while(j<i.length() && i[j]!=',')
            {
                t=t*10+(i[j]-'0');
                j++;
            }
             j++;
            
           //amount
            int amt=0;
            while(j<i.length() && i[j]!=',')
            {
                amt=amt*10+(i[j]-'0');
                j++;
            }
             j++;
            
           //city 
            string cty=""; 
            while(j<i.length() && i[j]!=',')
            {
                cty+=i[j];
                j++;
            }
            j++;
            
            name.push_back(nme);
            city.push_back(cty);
            time.push_back(t);
            amount.push_back(amt);
        }
        
        set<int>st2;
        for(int i=0;i<n;i++)
        {
            if(st2.find(i)==st2.end() && amount[i]>1000)
            {   
                res.push_back(transactions[i]);
                st2.insert(i);
            }
            
            for(int j=i+1;j<n;j++)
            {   
                if(name[i]==name[j] && city[i]!=city[j] && abs(time[i]-time[j])<=60 )
                {
                    cout<<transactions[i]<<" "<<transactions[j]<<"\n";
                    if(st2.find(i)==st2.end())
                    {
                       st2.insert(i);
                       res.push_back(transactions[i]); 
                    }
                    
                    if(st2.find(j)==st2.end())
                    {
                        st2.insert(j);
                       res.push_back(transactions[j]);
                    }
                    
                }
            }
           
        }
        
        return res;
        
       
        
        
    }
};