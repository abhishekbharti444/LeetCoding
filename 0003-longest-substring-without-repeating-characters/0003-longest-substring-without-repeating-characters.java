class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        Set<Character> set = new HashSet<>();

        int res = 0;
        while (right < n) {
            while (right < n && set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }
            set.add(s.charAt(right));
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}