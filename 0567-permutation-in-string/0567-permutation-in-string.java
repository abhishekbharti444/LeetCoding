class Solution {
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }
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

        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (int i = 0; i < m; ++i) {
            map1.put(s1.charAt(i), map1.getOrDefault(s1.charAt(i), 0) + 1);
        }

        while (right < n) {
            char ch = s2.charAt(right);
            map2.put(ch, map2.getOrDefault(s2.charAt(right), 0) + 1);
            while (contains(map1, map2)) {
                if (map1.equals(map2)) return true;
                eraseFromMap(map2, s2.charAt(left));
                left++;
            }
            right++;
        }
        return false;
    }
}