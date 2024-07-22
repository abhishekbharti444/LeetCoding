class TimeMap {
public:
    
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
          
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto index_itr = mp[key].upper_bound(timestamp);
        if (index_itr == mp[key].begin()) return "";
        index_itr--;
        return index_itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */