class MyHashSet {
public:
    vector<int> vec;
    MyHashSet() {
        
    }
    
    void add(int key) {
        vec.push_back(key);
    }
    
    void remove(int key) {
        int n = vec.size();
        vector<int> res(n); 
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == key) continue;
            res[i] = vec[i];
        }
        vec = res;
    }
    
    bool contains(int key) {
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            if (vec[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */