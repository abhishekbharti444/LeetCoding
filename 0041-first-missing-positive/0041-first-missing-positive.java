/**
 * Approach: Cyclic Sort
 *
 * Key insight: For an array of length n, the first missing positive must be in range [1, n+1].
 * We can use the array itself as a hash map by placing each number at its "correct" position:
 * - Number 1 should be at index 0
 * - Number 2 should be at index 1
 * - Number k should be at index k-1
 *
 * Algorithm:
 * 1. For each position, keep swapping until the number is in its correct place
 * 2. Scan the array to find the first position where nums[i] != i+1
 *
 * Time: O(n) - each element is moved at most once
 * Space: O(1) - only using the input array
 */
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Phase 1: Place each valid number in its correct position
        for (int i = 0; i < n; i++) {
            // Keep swapping until current position has correct number or invalid number
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] to its correct position at index (nums[i] - 1)
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        // Phase 2: Find first position with wrong number
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        // All positions [1,n] are filled correctly, so answer is n+1
        return n + 1;
    }
}