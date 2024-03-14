class Solution {
public:
    /*
        This approach is inspired by the solution section approach 2:
    
    */
    int util(vector<int>& nums, int goal) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int curr_sum = 0;
        int res = 0;
        while (right < n) {
            curr_sum += nums[right++];
            while (curr_sum > goal && left < right) {
                curr_sum -= nums[left];
                left++;
                
            }
            res += right - left + 1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return util(nums, goal) - util(nums, goal-1);
    }
};