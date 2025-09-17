class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        vec.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            int last = vec.back();
            if (nums[i] > last) vec.push_back(nums[i]);
            else {
                // Find nums[i] location in vec with binary search and replace it with new val
                int index = lower_bound(vec.begin(), vec.end(), nums[i]) - vec.begin();
                vec[index] = nums[i];
            }
        }
        return vec.size();
    }
};