class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;
        int mn = 1;
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int temp = nums[i] * mx;
            mx = max({nums[i], nums[i] * mx, nums[i] * mn});
            mn = min({nums[i], temp, nums[i] * mn});
            res = max(res, mx);
        }
        return res;
    }
};