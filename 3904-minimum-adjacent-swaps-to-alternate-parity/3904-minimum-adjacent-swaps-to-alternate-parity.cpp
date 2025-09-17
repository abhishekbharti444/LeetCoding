class Solution {
public:
    /*
    Approach Summary:
    1. Check feasibility: Valid alternating arrangement is only possible if counts of even/odd numbers differ by at most 1
    2. Calculate minimum swaps: For each valid starting pattern (even-first or odd-first), compute swaps needed to move elements to their target positions
    3. Greedy positioning: Each element at index i in the subsequence should move to position 2*i in the final array
    */
    
    // Calculate swaps needed to place elements at positions 0, 2, 4, 6...
    int calculateSwaps(vector<int>& indices) {
        int swaps = 0;
        for (int i = 0; i < indices.size(); ++i) {
            // Element at index i should be at position 2*i in final array
            swaps += abs(indices[i] - 2 * i);
        }
        return swaps;
    }
    
    int minSwaps(vector<int>& nums) {
        vector<int> evenIndices, oddIndices;
        
        // Collect indices of even and odd numbers
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) evenIndices.push_back(i);
            else oddIndices.push_back(i);
        }
        
        int evenCount = evenIndices.size();
        int oddCount = oddIndices.size();
        
        // Check if alternating arrangement is possible
        if (abs(evenCount - oddCount) > 1) return -1;
        
        int result = INT_MAX;
        
        // Try different starting patterns based on counts
        if (evenCount > oddCount) {
            // Must start with even (pattern: E-O-E-O...)
            result = calculateSwaps(evenIndices);
        }
        else if (oddCount > evenCount) {
            // Must start with odd (pattern: O-E-O-E...)
            result = calculateSwaps(oddIndices);
        }
        else {
            // Equal counts: try both patterns and take minimum
            result = min(calculateSwaps(evenIndices), calculateSwaps(oddIndices));
        }
        
        return result;
    }
};
