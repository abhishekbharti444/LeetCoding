/**
 * Approach: Sliding Window with Character Frequency Maps
 *
 * Key insight: Use sliding window to find the minimum substring of s that contains
 * all characters of t with their required frequencies. Expand window until valid,
 * then shrink from left while maintaining validity to find minimum.
 *
 * Algorithm:
 * 1. Build frequency map for string t
 * 2. Use sliding window on string s with two pointers
 * 3. Expand right pointer and add characters to window map
 * 4. When window contains all characters of t, try to shrink from left
 * 5. Track the minimum valid window found
 *
 * Time: O(m + n*k) where m = s.length(), n = t.length(), k = unique chars in t
 *       The sContainsT check runs in O(k) for each valid window
 * Space: O(m + n) for the two frequency maps
 */
class Solution {
    // Helper method to check if current window contains all characters of t
    public boolean sContainsT(Map<Character, Integer> sMap, Map<Character, Integer> tMap) {
        for (Map.Entry<Character, Integer> entry: tMap.entrySet()) {
            char ch = entry.getKey();
            int val = entry.getValue();
            if (!sMap.containsKey(ch) || sMap.get(ch) < val) return false;
        }
        return true;
    }

    // Helper method to decrement character count and remove if zero
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }

    public String minWindow(String s, String t) {
        int m = s.length();
        int n = t.length();
        int left = 0;
        int right = 0;
        int index = -1;  // Starting index of minimum window
        int resLen = Integer.MAX_VALUE;  // Length of minimum window

        Map<Character, Integer> sMap = new HashMap<>();  // Current window frequencies
        Map<Character, Integer> tMap = new HashMap<>();  // Target frequencies

        // Build frequency map for target string t
        for (int i = 0; i < n; ++i) {
            char ch = t.charAt(i);
            tMap.put(ch, tMap.getOrDefault(ch, 0) + 1);
        }

        // Sliding window on string s
        while (right < m) {
            char ch = s.charAt(right);
            // Expand window by adding current character
            sMap.put(ch, sMap.getOrDefault(ch, 0) + 1);

            // Try to shrink window while it remains valid
            while (sContainsT(sMap, tMap)) {
                // Remove leftmost character from window
                eraseFromMap(sMap, s.charAt(left));

                // Update minimum window if current is smaller
                if (resLen > right - left + 1) {
                    resLen = right - left + 1;
                    index = left;
                }
                left++;
            }
            right++;
        }

        // Return result or empty string if no valid window found
        if (resLen == Integer.MAX_VALUE) return "";
        return s.substring(index, index + resLen);
    }
}