class Solution {
public:
    vector<vector<char>> g;
    int m,n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void util(int x, int y) {
        if (!isValid(x, y) || g[x][y] == '0') return;
        
        g[x][y] = '0';
        
        for (int i = 0; i < 4; ++i) {
            int row = x + dx[i];
            int col = y + dy[i];
            util(row, col);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == '1') {
                    res++;
                    util(i, j);
                }
            }
        }
        return res;
    }
};