/**
 * Approach: Sliding Window with Character Frequency Maps
 *
 * Key insight: A permutation of s1 exists in s2 if there's a substring in s2 with
 * exactly the same character frequencies as s1. Use sliding window to check all
 * possible substrings of s2 with length equal to s1.
 *
 * Algorithm:
 * 1. Build frequency map for s1 (target pattern)
 * 2. Use sliding window on s2 with variable size
 * 3. Expand window by adding characters from s2
 * 4. When window contains all characters of s1, try to shrink from left
 * 5. Check if current window has exact same frequencies as s1
 *
 * Time: O(n + m*k) where n = s2.length(), m = s1.length(), k = unique chars in s1
 *       The contains() and equals() checks run in O(k) for each valid window
 * Space: O(m + k) for the two frequency maps
 */
class Solution {
    // Helper method to decrement character count and remove if zero
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }

    // Helper method to check if map2 contains all characters from map1 with sufficient counts
    public boolean contains(Map<Character, Integer> map1, Map<Character, Integer> map2) {
        for (Map.Entry<Character, Integer> entry : map1.entrySet()) {
            char ch = entry.getKey();
            int val = entry.getValue();
            if (!map2.containsKey(ch) || map2.get(ch) < val) return false;
        }
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int right = 0;
        int left = 0;

        Map<Character, Integer> map1 = new HashMap<>();  // Target frequencies (s1)
        Map<Character, Integer> map2 = new HashMap<>();  // Current window frequencies (s2)

        // Build frequency map for s1
        for (int i = 0; i < m; ++i) {
            map1.put(s1.charAt(i), map1.getOrDefault(s1.charAt(i), 0) + 1);
        }

        // Sliding window on s2
        while (right < n) {
            char ch = s2.charAt(right);
            // Expand window by adding current character
            map2.put(ch, map2.getOrDefault(s2.charAt(right), 0) + 1);

            // Shrink window while it contains all characters of s1
            while (contains(map1, map2)) {
                // Check if current window is exact permutation of s1
                if (map1.equals(map2)) return true;

                // Shrink window from left
                eraseFromMap(map2, s2.charAt(left));
                left++;
            }
            right++;
        }
        return false;
    }
}