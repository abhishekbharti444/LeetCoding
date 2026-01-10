/**
 * Approach: Sliding Window with HashMap
 *
 * Key insight: Anagrams have identical character frequencies. Instead of checking
 * every substring from scratch, we can maintain a sliding window of size n and
 * update character counts incrementally.
 *
 * Algorithm:
 * 1. Build frequency map for pattern p
 * 2. Use sliding window of size n on string s
 * 3. For each position, add new character and remove old character
 * 4. Compare window's frequency map with pattern's map
 *
 * Time: O(m + n) where m = s.length(), n = p.length()
 * Space: O(k) where k = unique characters in p
 */
class Solution {
    // Helper method to decrement character count and remove if zero
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }

    public List<Integer> findAnagrams(String s, String p) {
        int m = s.length();
        int n = p.length();
        List<Integer> res = new ArrayList<>();

        // Build frequency map for pattern
        Map<Character, Integer> pMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            pMap.put(p.charAt(i), pMap.getOrDefault(p.charAt(i), 0) + 1);
        }

        // Sliding window frequency map
        Map<Character, Integer> tempMap = new HashMap<>();

        for (int i = 0; i < m; ++i) {
            // Build initial window of size n
            if (i < n) {
                tempMap.put(s.charAt(i), tempMap.getOrDefault(s.charAt(i), 0) + 1);
                // Check if first complete window is an anagram
                if (i == n - 1 && tempMap.equals(pMap)) res.add(0);
                continue;
            }

            // Slide window: add new character, remove old character
            tempMap.put(s.charAt(i), tempMap.getOrDefault(s.charAt(i), 0) + 1);
            eraseFromMap(tempMap, s.charAt(i - n));

            // Check if current window is an anagram
            if (tempMap.equals(pMap)) {
                res.add(i - n + 1);  // Starting index of current window
            }
        }
        return res;
    }
}