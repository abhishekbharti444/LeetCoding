class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int k;
    int util(int index, int curr_k, vector<int>& nums) {
        if (index == n && curr_k == k) return 0;
        if (index == n) return INT_MAX;
        if (curr_k > k) return INT_MAX;
        if (dp[index][curr_k] != -1) return dp[index][curr_k];

        int ans = INT_MAX;
        int curr_xor = 0;
        for (int i = index; i < n; ++i) {
            curr_xor ^= nums[i];
            int next_xor = util(i + 1, curr_k + 1, nums);
            if (next_xor != INT_MAX) ans = min(ans, max(curr_xor, next_xor));
        }
        return dp[index][curr_k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        dp.resize(n+1, vector<int> (k+1, -1));
        return util(0, 0, nums);
    }
};