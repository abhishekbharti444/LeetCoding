class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, INT_MIN);
        vector<int> suf(n, INT_MAX);
        vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            if (i == 0) pre[i] = nums[i];
            else pre[i] = max(pre[i-1], nums[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            if (i == n-1) suf[i] = nums[i];
            else suf[i] = min(suf[i+1], nums[i]);
        }
        res[n-1] = pre[n-1];
        for (int i = n-2; i >= 0; --i) {
            res[i] = pre[i];
            // Bridge case
            if (pre[i] > suf[i+1]) {
                res[i] = res[i+1];
            }
        }
        return res;
    }
};