class Solution {
public:

    int r, c;
    vector<int> res;
    vector<vector<int>> dir = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    bool isValid(int x, int y) {
        return x >= 0 && x < r && y >= 0 && y < c;
    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        int x = 0;
        int y = 0;
        int curr_dir = 0;
        for (int i = 0; i < r * c; ++i) {
            // visit current cell
            res.push_back(mat[x][y]);
            vis[x][y] = true;
            // Find next cells
            int nx = x + dir[curr_dir][0];
            int ny = y + dir[curr_dir][1];

            // If next cell is invalid either due to out of bounds
            // or due that cell being visited; change the direction
            if (!isValid(nx, ny) || vis[nx][ny]) {
                curr_dir = (curr_dir + 1) % 4;
                nx = x + dir[curr_dir][0];
                ny = y + dir[curr_dir][1];
            }
            x = nx;
            y = ny;
        }
        return res;
    }
};