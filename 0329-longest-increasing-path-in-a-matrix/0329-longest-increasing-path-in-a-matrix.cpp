class Solution {
public:
    vector<vector<int>> mat;
    int m, n;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    vector<vector<int>> dp;
    int dfsUtil(int x, int y) {
        if (!isValid(x, y)) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        int max_val = 1;
        for (int i = 0; i < 4; ++i) {
            int r = x + dx[i];
            int c = y + dy[i];
            if (isValid(r, c) && mat[r][c] > mat[x][y]) max_val = max(max_val, 1 + dfsUtil(x + dx[i], y + dy[i]));
        }
        return dp[x][y] = max_val;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mat = matrix;
        m = mat.size();
        n = mat[0].size();
        dp.resize(m, vector<int> (n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfsUtil(i, j);
            }
        }
        int res = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};