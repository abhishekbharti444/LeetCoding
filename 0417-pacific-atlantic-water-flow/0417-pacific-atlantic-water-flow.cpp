class Solution {
public:
    vector<vector<int>> h;
    int m, n;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    vector<vector<bool>> vis, vis1;

    void util_pac(int x, int y, int last_val) {
        if (!isValid(x, y) || h[x][y] < last_val || vis[x][y]) return;
        
        vis[x][y] = true;
        util_pac(x + 1, y, h[x][y]);
        util_pac(x, y + 1, h[x][y]);
        util_pac(x - 1, y, h[x][y]);
        util_pac(x, y - 1, h[x][y]);
        
    }
    
    void util_atl(int x, int y, int last_val) {
        if (!isValid(x, y) || h[x][y] < last_val || vis1[x][y]) return;
        vis1[x][y] = true;
        util_atl(x - 1, y, h[x][y]);
        util_atl(x, y - 1, h[x][y]);
        util_atl(x + 1, y, h[x][y]);
        util_atl(x, y + 1, h[x][y]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        
        m = h.size();
        n = h[0].size();
        vis = vector<vector<bool>> (m, vector<bool> (n, false));
        vis1 = vis;
        for (int i = 0; i < m; ++i) {
            util_pac(i, 0, -1);
        }
        
        for (int j = 0; j < n; ++j) {
            util_pac(0, j, -1);
        }
        
        
        for (int i = 0; i < m; ++i) {
            util_atl(i, n-1, -1);
        }
        
        for (int j = 0; j < n; ++j) {
            util_atl(m-1, j, -1);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] && vis1[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};