class Solution {
public:
    vector<vector<char>> b;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int len;
    string target;
    int m, n;
    bool isValid(int x, int y) {
        return x >= 0 && y >=0 && x < m && y < n;
    }
    bool dfsUtil(int x, int y, int index, vector<vector<bool>>& vis) {
        if (index == len) return true;
        if (!isValid(x, y) || vis[x][y] || b[x][y] != target[index]) return false;
        vis[x][y] = true;
        bool res = false;
        for (int i = 0; i < 4; i++) {
            res = res || dfsUtil(x + dx[i], y + dy[i], index + 1, vis);
        }
        vis[x][y] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        b = board;
        len = target.size();
        m = b.size();
        n = b[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool>> vis(m, vector<bool> (n, false));
                if (dfsUtil(i, j, 0, vis)) return true;
            }
        }
        return false;
    }
};