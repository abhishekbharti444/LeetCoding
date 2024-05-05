class Solution {
public:
    /*
        Had to spend an hour debugging the memoization part: 
            I was doing memo[x][y][divisor] instead of memo[x][y][curr_sum]
            This is quite a crucial detail I missed. 
        
        Read this solution for understanding:
            https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/discuss/2678797/C%2B%2B-Java-Python-Clean-Top-Down-and-Bottom-Up-DP-(m-*-n-*-k)
    */
    
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int m,n;
    vector<vector<int>> g;
    int divisor;
    int util(int x, int y, int curr_sum) {
        if (x == m || y == n) return 0;
        if (x == m-1 && y == n-1) {
            if (((curr_sum + g[x][y]) % divisor) == 0) return 1;
            return 0;
            // return (curr_sum + g[x][y]) % divisor == 0;
        }
        if (memo[x][y][curr_sum] != -1) return memo[x][y][curr_sum];
        return memo[x][y][curr_sum] = (util(x + 1, y, (curr_sum + g[x][y]) % divisor) + util(x, y + 1, (curr_sum + g[x][y]) % divisor)) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        divisor = k;
        memo = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return util(0, 0, 0) % mod;
    }
};