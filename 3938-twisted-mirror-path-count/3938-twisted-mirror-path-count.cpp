class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    const int mod = 1e9 + 7;
    long long util(int x, int y, int dir) {
        if (x == m-1 && y == n-1) return 1LL;
        if (x >= m || y >= n) return 0LL;

        if (dp[x][y][dir] != -1) return dp[x][y][dir];

        if (g[x][y] == 1) { // Mirror cell
            if (dir == 0) { // You came from left side, you should go down
                return dp[x][y][dir] = util(x + 1, y, 1) % mod; // Your new direction would be top
            }
            else { // If you came from top, you should go right
                return dp[x][y][dir] = util(x, y + 1, 0) % mod; // Your new direction would be left
            }
        }

        long long right = util(x, y + 1, 0) % mod; // new direction is left
        long long down = util(x + 1, y, 1) % mod; // new direction is top
        dp[x][y][dir] = (right + down) % mod;
        return dp[x][y][dir];

    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        dp.resize(m, vector<vector<int>> (n, vector<int> (3, -1)));
        // Start with no direction = 2
        return util(0, 0, 2) % mod;
    }
};