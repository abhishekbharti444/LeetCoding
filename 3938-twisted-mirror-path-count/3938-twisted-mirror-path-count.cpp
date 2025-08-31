class Solution {
public:
    /*
    SOLUTION APPROACH:
    1. Dynamic Programming with State: Use 3D DP where dp[x][y][dir] represents number of paths 
    to reach (m-1, n-1) starting from position (x,y) with direction dir
    
    2. Direction Encoding: 
    - dir = 0: moving right (came from left)
    - dir = 1: moving down (came from top) 
    - dir = 2: initial state (no previous direction)
    
    3. Mirror Reflection Logic:
    - If moving right into mirror (dir=0): reflect down (new dir=1)
    - If moving down into mirror (dir=1): reflect right (new dir=0)
    - Continue reflecting until reaching non-mirror cell or going out of bounds
    
    4. Base Cases:
    - Reached destination (m-1, n-1): return 1 path
    - Out of bounds: return 0 paths
    
    5. Recurrence:
    - At mirror cell: forced reflection based on entry direction
    - At empty cell: can move both right and down, sum both possibilities
    
    6. Memoization: Cache results to avoid recomputation of subproblems
    
    Time Complexity: O(m*n*3) = O(m*n)
    Space Complexity: O(m*n*3) = O(m*n)
    */
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