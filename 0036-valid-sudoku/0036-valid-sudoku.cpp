class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<unordered_set<int>> row(m);
        vector<unordered_set<int>> col(n);
        vector<unordered_set<int>> box(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int box_num = (i/3) * 3 + j/3;
                if (row[i].find(board[i][j]) != row[i].end()) return false;
                if (col[j].find(board[i][j]) != col[j].end()) return false;
                if (box[box_num].find(board[i][j]) != box[box_num].end()) return false;
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[box_num].insert(board[i][j]);
            }
        }
        return true;
    }
};