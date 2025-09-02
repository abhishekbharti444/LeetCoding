/*
SOLUTION APPROACH: Strategic Insertion Analysis for LCT Subsequences

KEY INSIGHT: Instead of trying all insertion positions, focus on strategic placements:
1. Add 'L' at beginning - benefits all existing 'C' positions
2. Add 'T' at end - benefits all existing 'C' positions  
3. Add 'L'/'C'/'T' at optimal internal position

PRECOMPUTATION:
- pre[i]: Count of 'L' characters before and including position i
- suf[i]: Count of 'T' characters after and including position i

STRATEGIC OPTIONS:
- op1: Insert 'L' at beginning, then count LCT using all 'C' positions
- op2: Insert 'T' at end, then count LCT using all 'C' positions
- op3: Use existing string + best internal insertion

MATHEMATICAL CALCULATION:
- For each 'C' at position i: forms pre[i] × suf[i] LCT subsequences
- Adding 'L' at start: each 'C' gets (pre[i] + 1) × suf[i] subsequences
- Adding 'T' at end: each 'C' gets pre[i] × (suf[i] + 1) subsequences
*/

class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        
        // Prefix array: count of 'L' up to position i
        vector<int> pre(n, 0);
        if (s[0] == 'L') pre[0] = 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + (s[i] == 'L' ? 1 : 0);
        }
        
        // Suffix array: count of 'T' from position i onwards
        vector<int> suf(n, 0);
        if (s[n-1] == 'T') suf[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            suf[i] = suf[i+1] + (s[i] == 'T' ? 1 : 0);
        }
        
        long long op1 = 0;  // Strategy: Add 'L' at beginning
        long long op2 = 0;  // Strategy: Add 'T' at end
        long long op3 = 0;  // Strategy: Use existing string
        long long bestInternalInsertion = 0;  // Best internal insertion (insert 'C')
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'C') {
                // Each 'C' contributes to LCT count based on available L's and T's
                op1 += (long long)(pre[i] + 1) * suf[i]; // Extra 'L' at start
                op2 += (long long)pre[i] * (suf[i] + 1); // Extra 'T' at end  
                op3 += (long long)pre[i] * suf[i];       // No insertion
            }
            else {
                // For non-'C' positions, calculate potential if we insert 'C' here
                bestInternalInsertion = max(bestInternalInsertion, (long long)pre[i] * suf[i]);
            }
        }
        
        // Return best among all strategies
        return max({op1, op2, op3 + bestInternalInsertion});
    }
};
