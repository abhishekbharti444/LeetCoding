class Solution {
public:
    
    vector<vector<int>> g1, g2;
    int m, n;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    vector<vector<int>> vis;
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    bool util(int x, int y, bool flag) {
        if (!isValid(x, y) || vis[x][y] == 1 || g2[x][y] == 0) return true;
        
        vis[x][y] = 1;
        
        bool res = true;
        if (g1[x][y] == 0) flag = false;
        for (int i = 0; i < 4; ++i) {
            res = util(x + dx[i], y + dy[i], flag) && res;
        }
        return res && flag;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        g1 = grid1;
        g2 = grid2;
        m = g1.size();
        n = g1[0].size();
        int res = 0;
        vis = vector<vector<int>> (m, vector<int> (n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] == 0 && g2[i][j] == 1){
                    if (util(i, j, true)) {
                        res++;
                        cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }
        return res;
    }
};