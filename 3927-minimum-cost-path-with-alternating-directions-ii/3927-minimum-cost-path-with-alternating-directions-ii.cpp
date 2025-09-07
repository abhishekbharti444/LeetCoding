class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long> (n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) dp[i][j] = dp[i][j-1] + waitCost[i][j] + (j + 1);
                else if (j == 0) dp[i][j] = dp[i-1][j] + waitCost[i][j] + (i + 1);
                else {
                    dp[i][j] = waitCost[i][j] + min(dp[i-1][j], dp[i][j-1]) + ((i + 1) * (j + 1));
                }
            }
        }
        return dp[m-1][n-1] - waitCost[m-1][n-1];
    }
};