class LFUCache {
public:
    int sz;
    int minfreq;
    unordered_map<int,pair<int,int>>cache;//key->{value,freq}
    unordered_map<int,list<int>>freqmp;//frequency->list
    unordered_map<int,list<int>::iterator>itrmp;//key->listNodeAddreess
    
    LFUCache(int capacity) {
        sz=capacity;
        minfreq=1;
    }
    
    void update(int key)
    {
        int freq=cache[key].second;
        cache[key].second+=1;
        
        freqmp[freq].erase(itrmp[key]);
        
        freqmp[freq+1].push_front(key);
        
        itrmp[key]=freqmp[freq+1].begin();
        
        if(freqmp[minfreq].size()==0)
        {
            freqmp.erase(minfreq++);
        }
    }
    
    int get(int key) {
        
        if(!cache.count(key))
        {
            return -1;
        }
        update(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        
        if(sz<=0)
            return;
        
        int val=get(key);
        
        if(val!=-1)
        {
            update(key);
            cache[key].first=value;
            return;
        }
        
        if(cache.size()>=sz)
        {
            //delete least recently used in minimum freq list
            int freq=freqmp[minfreq].back();
            
            cache.erase(freq);
            itrmp.erase(freq);
            
            freqmp[minfreq].pop_back();
        }
        
        cache[key]={value,1};
        freqmp[1].push_front(key);
        itrmp[key]=freqmp[1].begin();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */