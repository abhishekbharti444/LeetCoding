class Solution {
public:
    vector<int> c;
    int n;
    vector<int> dp;
    int util(int curr) {
        if (curr < 0) return INT_MAX;
        if (curr == 0) return 0;
        if (dp[curr] != -1) return dp[curr];
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int next_res = util(curr - c[i]);
            if (next_res != INT_MAX) {
                res = min(res, 1 + next_res);
            }
        }
        return dp[curr] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        c = coins;
        sort(c.rbegin(), c.rend());
        n = c.size();
        if (amount == 0) return 0;
        dp.resize(amount + 1, -1);
        int res = util(amount);
        return res == INT_MAX ? -1 : res;
    }
};