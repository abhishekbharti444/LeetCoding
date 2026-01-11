/**
 * Approach: Sliding Window with Character Frequency Tracking
 *
 * Key insight: We can replace at most k characters to make all characters in a window
 * the same. A window is valid if (window_size - max_frequency) <= k, meaning we need
 * at most k replacements to make all characters match the most frequent one.
 *
 * Algorithm:
 * 1. Use sliding window with left and right pointers
 * 2. Track character frequencies in current window using HashMap
 * 3. Track the maximum frequency of any character seen so far (maxCount)
 * 4. When adding a character, update maxCount if this character's new frequency
 *    becomes the highest we've seen
 * 5. If (window_size - maxCount) > k, shrink window from left
 * 6. Update result with maximum valid window size
 *
 * Note: maxCount may not always reflect the true max in current window after
 * shrinking, but this doesn't affect correctness - we only care about finding
 * the maximum valid window size.
 *
 * Time: O(n) - each character processed at most twice
 * Space: O(1) - at most 26 characters in map for uppercase letters
 */
class Solution {
    // Helper method to decrement character count and remove if zero
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }

    public int characterReplacement(String s, int k) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int maxCount = 0;  // Max frequency of any character seen so far
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();

        while (right < n) {
            char ch = s.charAt(right);
            // Add current character to window
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            // Update maxCount if current character's frequency becomes the new maximum
            maxCount = Math.max(maxCount, map.get(ch));

            // Shrink window if invalid (need more than k replacements)
            while ((right - left + 1) - maxCount > k) {
                eraseFromMap(map, s.charAt(left));
                left++;
            }

            // Update result with current valid window size
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}