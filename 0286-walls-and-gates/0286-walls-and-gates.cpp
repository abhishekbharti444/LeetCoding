class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    const int INF = 2147483647;
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                pair<int, int> curr = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int row = curr.first + dx[j];
                    int col = curr.second + dy[j];
                    if (isValid(row, col, m, n)) {
                        if (rooms[row][col] == -1) continue;
                        if (rooms[row][col] > 1 + rooms[curr.first][curr.second]) {
                            rooms[row][col] = 1 + rooms[curr.first][curr.second];
                            q.push({row, col});
                        }
                    }
                }
            }
        }
    }
};