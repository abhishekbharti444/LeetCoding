class Solution {
public:
    vector<int> c;
    int n;
    vector<vector<int>> dp;
    int util(int curr, int index) {
        if (curr < 0 || index >= n) return 0; 
        if (curr == 0) return 1;
        if (dp[curr][index] != -1) return dp[curr][index];
        int use_coin = util(curr - c[index], index);
        int skip_coin = util(curr, index + 1);
        int res = use_coin + skip_coin;
        return dp[curr][index] = res;
    }
    int change(int amount, vector<int>& coins) {
        c = coins;
        n = c.size();
        dp.resize(amount + 1, vector<int> (n, -1));
        int ans = util(amount, 0);
        return ans;
    }
};