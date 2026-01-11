/**
 * Approach: Sliding Window with HashMap
 *
 * Key insight: This is equivalent to finding the longest subarray with at most 2 distinct
 * elements. Use sliding window where we expand right pointer and shrink from left when
 * we have more than 2 distinct fruit types.
 *
 * Algorithm:
 * 1. Use sliding window with left and right pointers
 * 2. Expand right pointer and add fruits to frequency map
 * 3. When map has more than 2 distinct fruits, shrink from left
 * 4. Track maximum window size (total fruits collected)
 *
 * Time: O(n) - each element processed at most twice
 * Space: O(1) - map stores at most 3 fruit types at any time
 */
class Solution {
    // Helper method to decrement fruit count and remove if zero
    public void eraseFromMap(Map<Integer, Integer> map, int key) {
        if (map.get(key) == 1) map.remove(key);
        else map.put(key, map.get(key) - 1);
    }

    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        Map<Integer, Integer> map = new HashMap<>();  // Fruit type -> count in current window

        int right = 0;
        int left = 0;
        int res = 0;

        while (right < n) {
            // Add current fruit to window
            map.put(fruits[right], map.getOrDefault(fruits[right], 0) + 1);

            // Shrink window if more than 2 distinct fruit types
            if (map.size() > 2) {
                eraseFromMap(map, fruits[left]);
                left++;
            }

            // Update maximum fruits collected
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}