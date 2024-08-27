class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 3) return 0;
        int left = 0;
        int right = n - 4;
        int res = INT_MAX;
        while (right < n) {
            res = min(res, nums[right] - nums[left]);
            right++;
            left++;
        }
        return res;
    }
};