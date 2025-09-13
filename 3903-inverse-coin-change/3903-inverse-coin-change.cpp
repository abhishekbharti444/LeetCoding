/*
APPROACH: Reverse Coin Change DP - Incremental Coin Discovery
1. Prepend dp[0] = 1 to represent base case (1 way to make amount 0)
2. Iterate through each potential coin denomination from 1 to n
3. If exactly 1 way exists to make amount i, then i must be a coin
4. Remove that coin's contribution from all larger amounts using reverse DP
5. Validate at each step - return empty if inconsistent
Time: O(n²), Space: O(n)
*/

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        
        // Create DP array with base case: dp[0] = 1 (one way to make 0)
        vector<int> dp;
        dp.push_back(1);                    // Base case: dp[0] = 1
        for (int a: numWays) dp.push_back(a); // Copy input: dp[1..n] = numWays[0..n-1]

        vector<int> res;
        
        // Check each potential coin denomination from 1 to n
        for (int i = 1; i <= n; ++i) {
            // If more than 1 way before finding coins, impossible configuration
            if (dp[i] > 1) return {};
            
            // Skip amounts that cannot be made (0 ways)
            if (dp[i] == 0) continue;
            
            // If exactly 1 way to make amount i, then i is a coin denomination
            res.push_back(i);
            
            // Remove this coin's contribution from all amounts j >= i
            for (int j = n; j >= i; --j) {
                // Reverse DP: subtract ways that used coin i
                dp[j] -= dp[j-i];
                
                // Negative ways indicate invalid coin configuration
                if (dp[j] < 0) return {};
            }
        }
        
        return res;
    }
};
