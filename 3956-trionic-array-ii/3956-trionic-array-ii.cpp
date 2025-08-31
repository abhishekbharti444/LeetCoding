class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(4, vector<long long> (n, -1e18));

        long long res = -1e18;
        for (int i = 0; i < n; ++i) {
            dp[0][i] = nums[i];
            if (i > 0) {
                if (nums[i] > nums[i-1]) {
                    dp[1][i] = max(dp[0][i-1] + nums[i], dp[1][i-1] + nums[i]);
                }
                if (nums[i] < nums[i-1]) {
                    dp[2][i] = max(dp[1][i-1] + nums[i], dp[2][i-1] + nums[i]);
                }
                if (nums[i] > nums[i-1]) {
                    dp[3][i] = max(dp[2][i-1] + nums[i], dp[3][i-1] + nums[i]);
                }
            }
            res = max(res, dp[3][i]);
        }
        return res;
    }
};