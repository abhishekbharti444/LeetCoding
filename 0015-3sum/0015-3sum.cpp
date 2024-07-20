class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // unordered_set<vector<int>> st;
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while (left < right) {
                int curr_sum = nums[left] + nums[right];
                if (curr_sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]) {
                        right--;
                        
                    }
                    left++;
                    right--;
                }
                else if (curr_sum < target) {
                    left++;
                }
                else right--;
            }
        }
        // for (auto a : st) res.push_back(a);
        return res;
    }
};