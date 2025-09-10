/*
PROBLEM: Longest Common Prefix After Removing Element
Remove each element and find max LCP among remaining adjacent pairs.

APPROACH: Prefix/Suffix Maximum + Bridge Gap Handling

KEY INSIGHT: When removing element at index i, remaining pairs split into:
1. LEFT SIDE: All pairs before the removed element  
2. RIGHT SIDE: All pairs after the removed element
3. BRIDGE GAP: New adjacency between elements i-1 and i+1

ALGORITHM:
1. Compute prefix maximums: pre[i] = max LCP from start up to position i
2. Compute suffix maximums: suf[i] = max LCP from position i to end  
3. For each removal: combine left max + right max + bridge pair

BRIDGE GAP CONCEPT:
Original: [a, b, c, d, e]  →  pairs: (a,b), (b,c), (c,d), (d,e)
Remove c: [a, b, _, d, e]  →  pairs: (a,b), (b,d), (d,e)
                                     ↑     ↑bridge↑
                                   left    gap    right

The bridge gap (b,d) is a NEW pair that didn't exist in original array!

EDGE CASES:
- Remove first element: only right side + no bridge
- Remove last element: only left side + no bridge  
- Remove middle: left + right + bridge
*/

class Solution {
public:
    // Calculate longest common prefix between two strings
    int similarity(string a, string b) {
        int index = 0;
        int m = a.size(), n = b.size();
        while (index < m && index < n && a[index] == b[index]) {
            index++;
        }
        return index;
    }
    
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> pre(n, 0);  // pre[i] = max LCP from pairs [0,1] to [i-1,i]
        vector<int> suf(n, 0);  // suf[i] = max LCP from pairs [i,i+1] to [n-2,n-1]
        
        // Build prefix maximums (left-to-right)
        int curr_max = 0;
        for (int i = 1; i < n; ++i) {
            int sim = similarity(words[i], words[i-1]);  // LCP of current adjacent pair
            curr_max = max(sim, curr_max);               // Running maximum
            pre[i] = curr_max;                           // Store max up to position i
        }
        
        // Build suffix maximums (right-to-left)  
        curr_max = 0;
        for (int i = n-2; i >= 0; --i) {
            int sim = similarity(words[i], words[i+1]);  // LCP of current adjacent pair
            curr_max = max(sim, curr_max);               // Running maximum
            suf[i] = curr_max;                           // Store max from position i
        }
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                // Remove first element: only right side remains
                // Remaining pairs: [1,2], [2,3], ..., [n-2,n-1]
                if (i + 1 < n) res[i] = suf[i+1];
            }
            else if (i == n-1) {
                // Remove last element: only left side remains  
                // Remaining pairs: [0,1], [1,2], ..., [n-3,n-2]
                if (i - 1 >= 0) res[i] = pre[i-1];
            }
            else {
                // Remove middle element: left + right + bridge gap
                // Left pairs: [0,1], ..., [i-2,i-1] → use pre[i-1]
                // Right pairs: [i+1,i+2], ..., [n-2,n-1] → use suf[i+1]  
                // Bridge gap: new pair [i-1, i+1] → calculate directly
                int bridge_lcp = similarity(words[i-1], words[i+1]);
                res[i] = max({bridge_lcp, suf[i+1], pre[i-1]});
            }
        }
        return res;
    }
};

/*
EXAMPLE TRACE: words = ["jump","run","run","jump","run"]
Individual LCPs: jump-run=0, run-run=3, run-jump=0, jump-run=0

PREFIX MAXIMUMS:
pre[1] = 0 (max from [0,1])
pre[2] = 3 (max from [0,1], [1,2]) 
pre[3] = 3 (max from [0,1], [1,2], [2,3])
pre[4] = 3 (max from [0,1], [1,2], [2,3], [3,4])

SUFFIX MAXIMUMS:  
suf[0] = 3 (max from [0,1], [1,2], [2,3], [3,4])
suf[1] = 3 (max from [1,2], [2,3], [3,4])
suf[2] = 0 (max from [2,3], [3,4])
suf[3] = 0 (max from [3,4])

RESULTS:
i=0: suf[1] = 3 ✓
i=1: max(similarity("jump","run"), suf[2], pre[0]) = max(0, 0, 0) = 0 ✓
i=2: max(similarity("run","jump"), suf[3], pre[1]) = max(0, 0, 0) = 0 ✓  
i=3: max(similarity("run","run"), suf[4], pre[2]) = max(3, 0, 3) = 3 ✓
i=4: pre[3] = 3 ✓

Output: [3,0,0,3,3] ✓
*/
