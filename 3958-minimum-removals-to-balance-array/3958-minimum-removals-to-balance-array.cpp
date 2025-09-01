/*
SOLUTION APPROACH: Sliding Window on Sorted Array

PROBLEM: Remove minimum elements to make array balanced (max ≤ k × min)

KEY INSIGHT: Problem transformation
- Instead of removing elements, find the LARGEST valid subarray
- A subarray is valid if max_element ≤ k × min_element
- Answer = total_elements - largest_valid_subarray_size

CRITICAL OBSERVATION: Sort the array first
- In sorted array, for any subarray [left, right]:
  * min_element = A[left] (leftmost)
  * max_element = A[right] (rightmost)
- Condition becomes: A[right] ≤ k × A[left]

SLIDING WINDOW TECHNIQUE:
- Expand right pointer to include more elements
- Shrink left pointer when condition A[right] ≤ k × A[left] is violated
- Track maximum valid window size encountered

ALGORITHM:
1. Sort array to enable min/max identification in subarrays
2. Use two pointers (left, right) to maintain valid window
3. For each right position, find leftmost valid left position
4. Update maximum valid subarray size
5. Return n - max_valid_size

WHY SORTING WORKS: After sorting, any contiguous subarray has its min at left end
and max at right end, making the balance condition easy to check.
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sort to enable efficient min/max tracking in subarrays
        vector<int> A = nums;
        sort(A.begin(), A.end());

        int left = 0;
        int right = 0;
        int maxValidSize = 0;  // Track largest valid subarray size
        
        // Sliding window to find largest valid subarray
        while (right < n) {
            // Shrink window from left while balance condition is violated
            // In sorted array: min = A[left], max = A[right]
            // Condition: A[right] ≤ k × A[left]
            while (left < n && left < right && 
                   (long long)A[left] * (long long)k < (long long)A[right]) {
                left++;  // Remove elements that make array unbalanced
            }
            
            // Update maximum valid subarray size
            maxValidSize = max(maxValidSize, right - left + 1);
            right++;  // Expand window to include next element
        }
        
        // Minimum removals = total elements - largest valid subarray
        return n - maxValidSize;
    }
};
