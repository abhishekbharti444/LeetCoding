/**
 * Approach: Sliding Window with HashSet
 *
 * Key insight: Use two pointers to maintain a window of unique characters.
 * When we encounter a duplicate, shrink the window from the left until
 * the duplicate is removed, then continue expanding from the right.
 *
 * Algorithm:
 * 1. Use left and right pointers to define current window
 * 2. Expand right pointer and add characters to set
 * 3. When duplicate found, shrink from left until duplicate removed
 * 4. Track maximum window size seen so far
 *
 * Time: O(n) - each character visited at most twice (once by right, once by left)
 * Space: O(min(m,n)) where m is charset size, n is string length
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        Set<Character> set = new HashSet<>();
        int res = 0;

        while (right < n) {
            // Shrink window from left while duplicate exists
            while (right < n && set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }

            // Add current character and update result
            set.add(s.charAt(right));
            res = Math.max(res, right - left + 1);
            right++;
        }

        return res;
    }
}