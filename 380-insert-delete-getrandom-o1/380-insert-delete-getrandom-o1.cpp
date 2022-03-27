class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>arr;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        
        mp[val]=arr.size();
        
        arr.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
         if(mp.find(val)==mp.end())
            return false;
        
        int pos=mp[val];
        arr[pos]=arr[arr.size()-1];
        mp[arr[arr.size()-1]]=pos;
        mp.erase(val);
        arr.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */