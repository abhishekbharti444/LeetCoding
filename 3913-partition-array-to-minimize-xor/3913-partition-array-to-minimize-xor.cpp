/*
APPROACH: Recursive DP with Memoization
- State: dp[index][subarrays_used] = min possible max XOR from index onwards
- For each position, try all possible subarray endings
- Return minimum of maximum XORs across all valid partitions
Time: O(n²k), Space: O(nk)
*/

class Solution {
private:
    vector<vector<int>> dp;
    int n, k;
    
    int solve(int idx, int used, vector<int>& nums) {
        // Base cases
        if (idx == n && used == k) return 0;           // Valid partition
        if (idx == n || used > k) return INT_MAX;      // Invalid state
        
        if (dp[idx][used] != -1) return dp[idx][used];
        
        int result = INT_MAX;
        int xor_val = 0;
        
        // Try all possible subarray endings from current index
        for (int end = idx; end < n; end++) {
            xor_val ^= nums[end];
            int remaining = solve(end + 1, used + 1, nums);
            
            if (remaining != INT_MAX) {
                result = min(result, max(xor_val, remaining));
            }
        }
        
        return dp[idx][used] = result;
    }
    
public:
    int minXor(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return solve(0, 0, nums);
    }
};
