class Solution {
public:
    
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) fresh++;
            }
        }
        
        int time = -1;
        
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                auto front = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int row = front.first + dx[j];
                    int col = front.second + dy[j];
                    if (isValid(row, col, m, n)) {
                        if (grid[row][col] == 1) {
                            grid[row][col] = 2;
                            q.push({row, col});
                            fresh--;
                        }
                    }
                }
            }
            time++;
        }
        if (fresh > 0) return -1;
        if (time == -1) return 0;
        return time;
    }
};