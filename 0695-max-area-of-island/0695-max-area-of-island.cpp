class Solution {
public:
    vector<vector<int>> g;
    int m, n;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n; 
    }
    int util(int x, int y) {
        if (!isValid(x, y) || g[x][y] == 0) return 0;
        g[x][y] = 0;
        int res = 1; 
        for (int i = 0; i < 4; ++i) {
            int row = x + dx[i];
            int col = y + dy[i];
            res += util(row, col);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        int res = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, util(i, j));
            }
        }
        return res;
    }
};