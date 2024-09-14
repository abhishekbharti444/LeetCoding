class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n = nums.size();
        
        int count = 0;
        int curr_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 6 == 0) {
                count++;
                curr_sum += nums[i];
            }
        }
        return count >= 1 ? curr_sum/count : 0;
    }
};