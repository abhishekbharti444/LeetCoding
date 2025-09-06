class Solution {
public:
    /*
     * Approach: Two-pass simulation
     * 
     * Pass 1: Calculate final string length by simulating all operations
     * Pass 2: Work backwards to find the kth character without building the actual string
     * 
     * Key insight: We can reverse each operation:
     * - '%' reverses position: k becomes (len-1-k)
     * - '#' halves length: if k >= half_len, subtract half_len from k
     * - '*' increases length by 1 (reverse of removal)
     * - lowercase: check if this is our target position
     * 
     * Time: O(n), Space: O(1)
     */
    
    char processStr(string s, long long k) {
        long long final_len = 0;
        int n = s.size();
        
        // Pass 1: Calculate final string length
        for (int i = 0; i < n; ++i) {
            if (s[i] == '%') continue;              // No length change
            else if (s[i] == '#') final_len *= 2;   // Double the string
            else if (s[i] == '*' && final_len > 0) final_len--; // Remove last char
            else if (islower(s[i])) final_len++;    // Add character
        }
        
        if (k >= final_len) return '.'; // k is out of bounds
        
        long long curr_len = final_len;
        
        // Pass 2: Work backwards to find kth character
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '%') {
                k = curr_len - 1 - k; // Reverse the position
            }
            else if (islower(s[i])) {
                if (k == curr_len - 1) return s[i]; // Found our character
                curr_len--; // Undo the addition
            } 
            else if (s[i] == '*') {
                curr_len++; // Undo the removal
            }
            else if (s[i] == '#') {
                curr_len /= 2; // Undo the duplication
                if (k >= curr_len) {
                    k -= curr_len; // Adjust position for second half
                }
            }
        }
        return '.';
    }
};
