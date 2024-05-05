class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int m,n;
    vector<vector<int>> g;
    int divisor;
    int util(int i, int j, int s) {
        if (i == m || j == n) return 0;
        if (i == m - 1 && j == n - 1) return ((s + g[i][j]) % divisor) == 0;
        if (memo[i][j][s] != -1) return memo[i][j][s];
        return memo[i][j][s] = (util(i + 1, j, (s + g[i][j]) % divisor) + util(i, j + 1, (s + g[i][j]) % divisor)) % mod;
    }
    // int util(int x, int y, int curr_sum) {
    //     if (x == m || y == n) return 0;
    //     if (x == m-1 && y == n-1) {
    //         if (((curr_sum + g[x][y]) % divisor) == 0) return 1;
    //         return 0;
    //         // return (curr_sum + g[x][y]) % divisor == 0;
    //     }
    //     if (memo[x][y][divisor] != -1) return memo[x][y][divisor];
    //     // curr_sum = (curr_sum + g[x][y]) % divisor;
    //     return memo[x][y][divisor] = (util(x + 1, y, (curr_sum + g[x][y]) % divisor) + util(x, y + 1, (curr_sum + g[x][y]) % divisor)) % mod;
    // }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        divisor = k;
        memo = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(divisor+1, -1)));
        return util(0, 0, 0) % mod;
    }
    
    // int mod = 1e9 + 7, m, n, K;
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     m = grid.size(), n = grid[0].size(), K = k;
    //     vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    //     return dfs(0, 0, 0, grid, dp);
    // }
    // int dfs(int i, int j, int s, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    //     if (i == m || j == n) return 0;
    //     if (i == m - 1 && j == n - 1) return ((s + grid[i][j]) % K) == 0;
    //     if (dp[i][j][s] != -1) return dp[i][j][s];
    //     return dp[i][j][s] = (dfs(i + 1, j, (s + grid[i][j]) % K, grid, dp) + dfs(i, j + 1, (s + grid[i][j]) % K, grid, dp)) % mod;
    // }
};