class Solution {
public:
    struct TrieNode {
        bool is_word;
        unordered_map<char, TrieNode*> next;
    };
    TrieNode* root = new TrieNode();
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch: word) {
            if (!curr->next.contains(ch)) {
                curr->next[ch] = new TrieNode();
            }
            curr = curr->next[ch];
        }
        curr->is_word = true;
    }
    bool search(string prefix) {
        TrieNode* curr = root;
        for (char ch: prefix) {
            if (!curr->next.contains(ch)) return false;
            curr = curr->next[ch];
        }
        return curr->is_word;
    }
    bool hasPrefix(string prefix) {
        TrieNode* curr = root;
        for (char ch: prefix) {
            if (!curr->next.contains(ch)) return false;
            curr = curr->next[ch];
        }
        return true;
    }

    unordered_set<string> res;
    int m, n;
    vector<vector<char>> b;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    void dfsUtil(int x, int y, string curr_str, vector<vector<bool>>& vis, TrieNode* curr) {
        if (!isValid(x, y) || vis[x][y] || !curr->next.contains(b[x][y])) return;
        vis[x][y] = true;
        char ch = b[x][y];
        curr_str.push_back(ch);
        curr = curr->next[ch];
        if (curr->is_word) res.insert(curr_str);
        for (int i = 0; i < 4; ++i) {
            dfsUtil(x + dx[i], y + dy[i], curr_str, vis, curr);
        }
        curr_str.pop_back();
        vis[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& word: words) insert(word);
        b = board;
        m = b.size();
        n = b[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool>> vis(m, vector<bool> (n, false));
                string curr_str;
                dfsUtil(i, j, curr_str, vis, root);
            }
        }
        vector<string> ans;
        for (auto& el: res) ans.push_back(el);
        return ans;
    }
};