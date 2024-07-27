class Solution {
public:
    
    vector<vector<char>> b;
    string w;
    
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int len; 
    int m, n;
    vector<vector<int>> vis;
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    bool util(int x, int y, int index) {
        if (index == len) return true;
        if (index == len - 1) return b[x][y] == w[index];
        if (b[x][y] != w[index]) return false;
        

        char ch = b[x][y];
        b[x][y] = '@';
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            int row = x + dx[i];
            int col = y + dy[i];
            if (isValid(row, col, m, n) && b[row][col] != '@') res = res || util(row, col, index + 1);
        }
        b[x][y] = ch;
        return res;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        w = word;
        m = b.size();
        n = b[0].size();
        len = w.size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (util(i, j, 0)) return true;
            }
        }
        return false;
    }
};