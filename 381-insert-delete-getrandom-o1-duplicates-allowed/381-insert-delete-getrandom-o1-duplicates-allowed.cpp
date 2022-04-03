class RandomizedCollection {
public:
    unordered_map<int,vector<int>>mp;
    vector<int>arr;
    
    RandomizedCollection() { 
    }
    
    bool insert(int val) {
        bool k=true;
        
        if(mp.find(val)!=mp.end() && mp[val].size()>0)
            k=false;
        
        mp[val].push_back(arr.size());
        arr.push_back(val);
        
        return k;
    }
    
    bool remove(int val) {
        
        if(mp.find(val)==mp.end() || mp[val].size()<=0)
            return false;
        
        //last element
        int last=arr.back();
        
        //preventing edge cases
        if(last==val)
        {
            mp[last].pop_back();
            arr.pop_back();
            return true;
        }
        
        //vector index of val
        int vec_idx=mp[val][mp[val].size()-1];
        
        //swapping
        swap(arr[vec_idx],arr[arr.size()-1]);
        
        //delete from vector
        arr.pop_back();
        
        //delete val fromt map
        mp[val].pop_back();
        
        //delete last from map
        mp[last].pop_back();
        
        //insert val's index in map
        mp[last].push_back(vec_idx);
        
        //sort mp[last] 
        sort(mp[last].begin(),mp[last].end());
        
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */