class Solution {
public:
    vector<int> A;
    int n;
    int target;
    vector<vector<int>> memo;
    bool util(int curr_sum, int index) {
        if (curr_sum > target || index >= n) return false;
        if (curr_sum == target) return true;

        if (memo[curr_sum][index] != -1) return memo[curr_sum][index] == 1;
        // Skip this index
        bool skip_case = util(curr_sum, index + 1);

        // Add to the curr_sum
        bool use_case = util(curr_sum + A[index], index + 1);
        memo[curr_sum][index] = skip_case || use_case;
        return memo[curr_sum][index];
    }
    bool canPartition(vector<int>& nums) {
        A = nums;
        n = A.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        target = total/2;
        memo.resize(target + 1, vector<int> (n, -1));
        return util(0, 0);
    }
};