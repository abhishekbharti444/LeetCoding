class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int mask = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) mask &= nums[i];
        }
        return mask == INT_MAX ? 0 : mask;
    }
};