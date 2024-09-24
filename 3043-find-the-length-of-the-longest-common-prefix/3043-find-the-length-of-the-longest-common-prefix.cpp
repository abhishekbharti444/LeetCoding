class Solution {
public:
    
    
    struct TrieNode {
        // bool isWord = false;
        unordered_map<char, TrieNode*> next;
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* curr = root;
        
        for (auto ch : word) {
            if (curr->next[ch] == NULL) {
                TrieNode* new_node = new TrieNode();
                curr->next[ch] = new_node;
            }
            curr = curr->next[ch];
        }
        // curr->isWord = true;
    }
    bool search(string word) {
        TrieNode* curr = root;
        
        for (auto ch : word) {
            if (curr->next[ch] == NULL) return false;
            curr = curr->next[ch];
        }
        // return curr->isWord;
        return true;
    }
    
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for (int a : arr1) {
            string curr = to_string(a);
            for (int i = 0; i < curr.size(); ++i) {
                string subs = curr.substr(0, i + 1);
                insert(subs);
            }
        }
        int res = 0;
        for (int a : arr2) {
            string curr = to_string(a);
            
            for (int i = 0; i < curr.size(); ++i) {
                string subs = curr.substr(0, i + 1);
                int n = subs.size();
                if (search(subs)) res = max(res, n);
            }
        }
        return res;
    }
};