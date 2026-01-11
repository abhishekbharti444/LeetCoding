/**
 * Approach: Monotonic Decreasing Deque
 *
 * Key insight: Use a deque to maintain indices of array elements in decreasing order
 * of their values. The front of deque always contains the index of maximum element
 * in current window. Remove indices that are outside current window and smaller
 * elements that can never be maximum.
 *
 * Algorithm:
 * 1. Build initial window of size k using deque
 * 2. For each subsequent position, slide the window:
 *    - Remove indices outside current window from front
 *    - Remove smaller elements from back (they can't be maximum)
 *    - Add current index to back
 *    - Front of deque gives maximum of current window
 *
 * Time: O(n) - each element added and removed at most once from deque
 * Space: O(k) - deque stores at most k indices
 */
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();  // Stores indices in decreasing order of values
        int[] res = new int[n - k + 1];

        // Build initial window of size k
        for (int i = 0; i < k; ++i) {
            // Remove smaller elements from back - they can't be maximum
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }
            dq.addLast(i);
        }

        // Store maximum of first window
        int index = 0;
        res[index] = nums[dq.peekFirst()];
        index++;

        // Process remaining elements
        for (int i = k; i < n; ++i) {
            // Remove smaller elements from back
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }

            // Remove indices outside current window from front
            while (!dq.isEmpty() && i - dq.peekFirst() >= k) {
                dq.pollFirst();
            }

            // Add current index
            dq.addLast(i);

            // Front of deque is maximum of current window
            res[index] = nums[dq.peekFirst()];
            index++;
        }
        return res;
    }
}