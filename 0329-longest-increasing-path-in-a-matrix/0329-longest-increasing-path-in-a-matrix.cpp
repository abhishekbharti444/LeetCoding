class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> indeg(m, vector<int> (n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int r = i + dx[k];
                    int c = j + dy[k];
                    if (isValid(r, c, m, n) && mat[r][c] > mat[i][j]) indeg[r][c]++;
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (indeg[i][j] == 0) q.push({i, j});
            }
        }
        int res = 0;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                auto [x, y] = q.front();
                q.pop();
                // visit the neighbors
                for (int index = 0; index < 4; ++index) {
                    int r = x + dx[index];
                    int c = y + dy[index];
                    if (isValid(r, c, m, n) && mat[r][c] > mat[x][y]) {
                        indeg[r][c]--;
                        if (indeg[r][c] == 0) q.push({r, c});
                    }
                }
            }
            res++;  
        }
        return res;
    }
};