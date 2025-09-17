class MapSum {
public:
    /*
    Approach Summary:
    1. Use Trie to store prefixes with cumulative sums at each node
    2. Each Trie node maintains sum of all words that pass through it
    3. Handle key updates by subtracting old value and adding new value to affected nodes
    4. Use hash map to track previous values for update operations
    */
    
    struct TrieNode {
        int sum;                                    // Sum of all words passing through this node
        unordered_map<char, TrieNode*> next;      // Children nodes
    };
    
    TrieNode* root;
    unordered_map<string, int> mp;                // Tracks previous values for updates
    
    void insertTrie(string word, int val) {
        TrieNode* curr = root;
        int prev_val = 0;
        
        // Get previous value if key already exists (for updates)
        if (mp.contains(word)) prev_val = mp[word];
        
        // Traverse/build path for the word
        for (char ch: word) {
            if (!curr->next.contains(ch)) {
                curr->next[ch] = new TrieNode();
            }
            curr = curr->next[ch];
            
            // Update sum: remove old contribution, add new contribution
            curr->sum -= prev_val;
            curr->sum += val;
        }
        
        // Store current value for future updates
        mp[word] = val;
    }
    
    int searchTrie(string prefix) {
        TrieNode* curr = root;
        
        // Navigate to the end of prefix
        for (char ch: prefix) {
            if (!curr->next.contains(ch)) {
                return 0;  // Prefix doesn't exist
            }
            curr = curr->next[ch];
        }
        
        // Return sum of all words with this prefix
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
