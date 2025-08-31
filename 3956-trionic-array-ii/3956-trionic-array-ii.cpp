
class Solution {
public:
/*
SOLUTION APPROACH: 4-State DP for Trionic Subarray

PROBLEM: Find max sum of subarray with pattern: increasing → decreasing → increasing

    KEY INSIGHT: Model trionic pattern as state machine progression
    - State 0: Single element (starting point)
    - State 1: Strictly increasing phase  
    - State 2: Strictly decreasing phase
    - State 3: Final strictly increasing phase (complete trionic)

    DP DEFINITION: dp[state][i] = max sum ending at position i in given state

    STATE TRANSITIONS:
    - State 0→1: Start increasing sequence (need a[i] > a[i-1])
    - State 1→1: Extend increasing sequence (need a[i] > a[i-1]) 
    - State 1→2: Start decreasing phase (need a[i] < a[i-1])
    - State 2→2: Extend decreasing sequence (need a[i] < a[i-1])
    - State 2→3: Start final increasing (need a[i] > a[i-1])
    - State 3→3: Extend final increasing (need a[i] > a[i-1])

    RECURRENCE LOGIC: At each position, choose best between:
    1. Transition from previous state (start new phase)
    2. Continue current state (extend current phase)

    ANSWER: Maximum value in dp[3] (complete trionic patterns)
*/

    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();
        
        // dp[state][position] = max sum ending at position in given state
        vector<vector<long long>> dp(4, vector<long long>(n, -1e18));
        
        long long ans = -1e18;
        
        for(int i = 0; i < n; i++) {
            // State 0: Can always start fresh with single element
            dp[0][i] = a[i];
            
            if(i > 0) {
                // State 1: First increasing phase (need a[i] > a[i-1])
                if(a[i] > a[i - 1]) {
                    dp[1][i] = max(dp[0][i - 1] + a[i],    // Start from single element
                                   dp[1][i - 1] + a[i]);   // Extend existing increasing
                }
                
                // State 2: Decreasing phase (need a[i] < a[i-1])  
                if(a[i] < a[i - 1]) {
                    dp[2][i] = max(dp[1][i - 1] + a[i],    // Transition from increasing
                                   dp[2][i - 1] + a[i]);   // Extend existing decreasing
                }
                
                // State 3: Final increasing phase (need a[i] > a[i-1])
                if(a[i] > a[i - 1]) {
                    dp[3][i] = max(dp[2][i - 1] + a[i],    // Transition from decreasing  
                                   dp[3][i - 1] + a[i]);   // Extend existing final increasing
                }
            }
            
            // Track maximum complete trionic sum
            ans = max(ans, dp[3][i]);
        }
        
        return ans;
    }
};


/*
Recurrence Derivation
The recurrence comes from analyzing how we can reach state 1 at position i:

State 1 Definition
dp[1][i] = maximum sum of a strictly increasing sequence ending at position i

Two Ways to Achieve This:
Option 1: Start new increasing sequence

We were at state 0 (single element) at position i-1

Now extend it to position i to form a 2-element increasing sequence

Contribution: dp[0][i-1] + a[i]

Option 2: Extend existing increasing sequence

We already had an increasing sequence ending at position i-1 (state 1)

Extend this sequence by adding a[i]

Contribution: dp[1][i-1] + a[i]

*/
