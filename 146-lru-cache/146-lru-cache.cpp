class LRUCache {
    
    int capacity;
    list<int>q;
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>pos;
    
    void cache(int key)
    {
        if(pos.find(key)!=pos.end())
        {
            q.erase(pos[key]);
        }   
        else if(q.size()>=capacity)
        {
            int k=q.back();
            q.pop_back();
            pos.erase(k);
            mp.erase(k);
        }
        
        //making it most used one
        q.push_front(key);
        pos[key]=q.begin();
    }   
    
public:
    LRUCache(int capacity) {
       this->capacity=capacity; 
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {    
           cache(key);
           return mp[key]; 
        }
        return -1;
    }
    
    void put(int key, int value) {
         cache(key);
         mp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */