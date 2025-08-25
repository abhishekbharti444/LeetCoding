class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int maxVal = 0;
        for (auto& row : grid) 
            for (int val : row) 
                maxVal = max(maxVal, val);
        
        vector<vector<int>> cost(m, vector<int>(n));
        vector<int> dp(maxVal + 1, INT_MAX);
        
        for (int teleports = 0; teleports <= k; teleports++) {
            // Reverse DP: cost[i][j] = min cost FROM (i,j) TO destination
            for (int i = m-1; i >= 0; i--) {
                for (int j = n-1; j >= 0; j--) {
                    if (i == m-1 && j == n-1) {
                        cost[i][j] = 0;
                    } else {
                        cost[i][j] = INT_MAX;
                        // Move right
                        if (j+1 < n) cost[i][j] = min(cost[i][j], cost[i][j+1] + grid[i][j+1]);
                        // Move down
                        if (i+1 < m) cost[i][j] = min(cost[i][j], cost[i+1][j] + grid[i+1][j]);
                        // Teleport (if available)
                        if (teleports > 0) cost[i][j] = min(cost[i][j], dp[grid[i][j]]);
                    }
                }
            }
            
            // Update dp for next iteration
            fill(dp.begin(), dp.end(), INT_MAX);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[grid[i][j]] = min(dp[grid[i][j]], cost[i][j]);
                }
            }
            // FIXED: Correct prefix minimum direction
            for (int v = 1; v <= maxVal; v++) {
                dp[v] = min(dp[v], dp[v-1]);
            }
        }
        
        return cost[0][0];
    }
};
