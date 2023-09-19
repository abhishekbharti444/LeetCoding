class LRUCache {
public:
    
    
    int cap;
    list<pair<int, int>> ls;
    unordered_map<int, list<pair<int, int>> :: iterator> cache;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // If not found
        if (cache.find(key) == cache.end()) return -1;
        
        // Get the itr of this key and it's corresponding value also 
        auto itr = cache[key];
        int upd_val = itr->second;
        int upd_key = itr->first;
        
        // Erase this guy from it's current location
        ls.erase(itr);
        
        // Push it back to the last of the list
        ls.push_back({upd_key, upd_val});
        auto it = prev(ls.end());
        
        // Update the iterator of this key
        cache[key] = it;
        return upd_val;
    }
    
    void put(int key, int value) {
        // What if the key already exists, delete that SOAB
        if (cache.find(key) != cache.end()) {
            auto itr = cache[key];
            ls.erase(itr);
            cache.erase(key);
        }
        
        // Check if it's going to exceed the capacity after adding this key value, 
        // delete the first entry of the list and it's corresponding entry in the cache.
        if (cache.size() >= cap) {
            auto itr = ls.begin();
            
            int del_val = itr->second;
            int del_key = itr->first;
            ls.erase(itr);
            cache.erase(del_key);
        }
        
        ls.push_back({key, value});
        auto itr = prev(ls.end());
        cache[key] = itr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */