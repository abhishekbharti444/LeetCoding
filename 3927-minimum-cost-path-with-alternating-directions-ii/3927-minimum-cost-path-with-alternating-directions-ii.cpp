class Solution {
public:
    /*
     * Approach: Dynamic Programming with Alternating Cost Pattern
     * 
     * Key insight: Due to alternating move/wait pattern, every cell visit involves:
     * 1. Odd second: Move to cell → pay entry cost (i+1)*(j+1)
     * 2. Even second: Wait in cell → pay waitCost[i][j]
     * 
     * Exception: No waiting required at destination cell
     * 
     * DP state: dp[i][j] = minimum cost to reach cell (i,j) including wait cost
     * Transition: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + entry_cost + wait_cost
     * 
     * Time: O(m*n), Space: O(m*n)
     */
    
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Base case: Start at (0,0) on second 1, pay entry cost only
        dp[0][0] = 1; // Entry cost for (0,0) is (0+1)*(0+1) = 1
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                long long entryCost = (long long)(i + 1) * (j + 1);
                
                if (i == 0) {
                    // Can only come from left
                    dp[i][j] = dp[i][j-1] + waitCost[i][j] + entryCost;
                }
                else if (j == 0) {
                    // Can only come from top
                    dp[i][j] = dp[i-1][j] + waitCost[i][j] + entryCost;
                }
                else {
                    // Choose minimum cost path (from top or left)
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + waitCost[i][j] + entryCost;
                }
            }
        }
        
        // Subtract wait cost at destination since we don't wait there
        return dp[m-1][n-1] - waitCost[m-1][n-1];
    }
};
