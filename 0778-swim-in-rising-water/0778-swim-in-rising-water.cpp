#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    vvi g;
    int m, n;
    vvi vis;
    vi dx = {0, 0, 1, -1};
    vi dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x < m && y < n && x >= 0 && y >= 0;
    }
    bool util(int x, int y, int val) {
        if (!isValid(x, y) || vis[x][y] == 1 || g[x][y] > val) return false;
        if (x == m-1 && y == n-1) return true;
        vis[x][y] = 1;
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            res = util(x + dx[i], y + dy[i], val) || res;
        }
        return res;
    }
    bool check(int val) {
        vis = vvi (m, vi(n, 0));
        return util(0, 0, val);
    }
    int swimInWater(vector<vector<int>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                low = min(low, g[i][j]);
                high = max(high, g[i][j]);
            }
        }
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            
            if (check(mid)) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};