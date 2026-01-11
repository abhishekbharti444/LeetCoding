class Solution {
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();
        while (right < n) {
            char ch = s.charAt(right);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            maxCount = Math.max(maxCount, map.get(ch));

            while ((right - left + 1) - maxCount > k) {
                eraseFromMap(map, s.charAt(left));
                left++;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}