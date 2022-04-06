class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>>mp;
    
    TimeMap() {
        
    }    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp[key].size()==0)
            return "";
            
        int l=0,r=mp[key].size()-1,idx=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mp[key][mid].first<=timestamp)
            {
                idx=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        if(mp[key][idx].first<=timestamp)
            return mp[key][idx].second;
    
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */