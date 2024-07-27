class Solution {
public:
    
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    int m, n;
    vector<vector<char>> b;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    void util(int x, int y, vector<vector<char>>& board) {
        if (!isValid(x, y) || board[x][y] != 'O') return;
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            util(x + dx[i], y + dy[i], board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        b = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || i == m-1 || j == n-1) util(i, j, b);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j] == '.') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};