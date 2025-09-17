class MapSum {
public:
    struct TrieNode {
        int sum;
        unordered_map<char, TrieNode*> next;
    };
    TrieNode* root;
    unordered_map<string, int> mp;
    void insertTrie(string word, int val) {
        TrieNode* curr = root;
        int prev_val = 0;
        if (mp.contains(word)) prev_val = mp[word];
        for (char ch: word) {
            if (!curr->next.contains(ch)) {
                curr->next[ch] = new TrieNode();
            }
            curr = curr->next[ch];
            curr->sum -= prev_val;
            curr->sum += val;
        }
        mp[word] = val;
    }
    int searchTrie(string prefix) {
        TrieNode* curr = root;
        for (char ch: prefix) {
            if (!curr->next.contains(ch)) {
                return 0;
            }
            curr = curr->next[ch];
        }
        return curr->sum;
    }

    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        insertTrie(key, val);
    }
    
    int sum(string prefix) {
        return searchTrie(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */