class Solution {
    public boolean sContainsT(Map<Character, Integer> sMap, Map<Character, Integer> tMap) {
        for (Map.Entry<Character, Integer> entry: tMap.entrySet()) {
            char ch = entry.getKey();
            int val = entry.getValue();
            if (!sMap.containsKey(ch) || sMap.get(ch) < val) return false;
        }
        return true;
    }
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }
    public String minWindow(String s, String t) {
        int m = s.length();
        int n = t.length();
        int left = 0;
        int right = 0;
        int index = -1;
        int resLen = Integer.MAX_VALUE;
        Map<Character, Integer> sMap = new HashMap<>();
        Map<Character, Integer> tMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            char ch = t.charAt(i);
            tMap.put(ch, tMap.getOrDefault(ch, 0) + 1);
        }
        while (right < m) {
            char ch = s.charAt(right);
            sMap.put(ch, sMap.getOrDefault(ch, 0) + 1);

            while (sContainsT(sMap, tMap)) {
                eraseFromMap(sMap, s.charAt(left));
                // Capture a res
                if (resLen > right - left + 1) {
                    resLen = right - left + 1;
                    index = left;
                }
                left++;
            }
            right++;
        } 
        if (resLen == Integer.MAX_VALUE) return "";
        return s.substring(index, index + resLen);
    }
}