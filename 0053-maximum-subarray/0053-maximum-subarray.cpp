class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int n = nums.size();
        int res = curr_sum;
        for (int i = 1; i < n; ++i) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            res = max(res, curr_sum);
        }
        return res;
    }
};