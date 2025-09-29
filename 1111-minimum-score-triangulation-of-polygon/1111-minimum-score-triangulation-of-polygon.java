class Solution {
    // Read this solution:
    // https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/7232401/dynamic-programming-recursion-bottom-up-top-down-solution-explained
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] dp = new int[n][n];
        /*
        Bottom-up approach processed i in reverse order (from n−1 to 0).
        This ensures that when we compute dp[i][j], the values dp[i][k] and dp[k][j] 
        have already been computed.
        */
        for (int i = n-1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = Math.min(dp[i][j] == 0 ? Integer.MAX_VALUE : dp[i][j], 
                        dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]
                    );
                }
            }
        }
        return dp[0][n-1];
    }
}