class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int r, c;
    vector<vector<bool>> vis;
    vector<vector<int>> g;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < r && y < c;
    }
    int dfsUtil(int x, int y) {
        if (!isValid(x, y) || g[x][y] == 0 || vis[x][y]) return 0;
        long long res = 0;
        vis[x][y] = true;
        res += (long long)g[x][y];
        for (int i = 0; i < dir.size(); ++i) {
            res += (long long)dfsUtil(x + dir[i][0], y + dir[i][1]);
        }
        return res;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        g = grid;
        r = g.size();
        c = g[0].size();
        int ans = 0;
        vis.resize(r, vector<bool> (c, false));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!vis[i][j] && g[i][j]) {
                    int island_val = dfsUtil(i, j);
                    // cout<<island_val<<endl;
                    if (island_val != 0 && island_val % k == 0) ans ++;
                }
            }
        }
        return ans;
    }
};