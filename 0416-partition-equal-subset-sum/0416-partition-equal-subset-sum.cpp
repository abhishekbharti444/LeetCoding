class Solution {
public:
    vector<vector<int>> memo;
    bool util(vector<int>& nums, int target, int curr_sum, int index) {
        if (index == nums.size()) return false;
        if (curr_sum >= target) {
            if (curr_sum == target) return true;
            return false;
        }
        if (memo[curr_sum][index] != -1) return memo[curr_sum][index] == 1 ? true : false;
        bool choose = util(nums, target, curr_sum + nums[index], index + 1);
        bool no_choose = util(nums, target, curr_sum, index + 1);
        bool res = choose || no_choose;
        memo[curr_sum][index] = res == true ? 1 : 0;
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2 != 0) return false;
        
        int target = total_sum/2;
        memo = vector<vector<int>> (target + 1, vector<int> (nums.size(), -1));
        return util(nums, target, 0, 0);
    }
};