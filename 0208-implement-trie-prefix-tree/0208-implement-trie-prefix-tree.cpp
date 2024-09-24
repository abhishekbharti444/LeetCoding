class Trie {
public:
    
    struct TrieNode {
        bool isWord = false;
        unordered_map<char, TrieNode*> next;
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (curr->next[ch] == NULL) {
                // create a new node
                TrieNode* new_node = new TrieNode();
                curr->next[ch] = new_node;
            }
            curr = curr->next[ch];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for (auto ch: word) {
            if (curr->next[ch] == NULL) return false;
            curr = curr->next[ch];
        }
        return curr->isWord ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for (auto ch : prefix) {
            if (curr->next[ch] == NULL) return false;
            curr = curr->next[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */