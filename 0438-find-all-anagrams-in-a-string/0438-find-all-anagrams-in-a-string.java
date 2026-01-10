class Solution {
    public void eraseFromMap(Map<Character, Integer> map, char ch) {
        if (map.get(ch) == 1) map.remove(ch);
        else map.put(ch, map.get(ch) - 1);
    }
    public List<Integer> findAnagrams(String s, String p) {
        int m = s.length();
        int n = p.length();
        Map<Character, Integer> pMap = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            pMap.put(p.charAt(i), pMap.getOrDefault(p.charAt(i), 0) + 1);
        }
        Map<Character, Integer> tempMap = new HashMap<>();

        for (int i = 0; i < m; ++i) {
            if (i < n) {
                tempMap.put(s.charAt(i), tempMap.getOrDefault(s.charAt(i), 0) + 1);
                if (i == n -1 && tempMap.equals(pMap)) res.add(0);
                continue;
            }
            tempMap.put(s.charAt(i), tempMap.getOrDefault(s.charAt(i), 0) + 1);

            eraseFromMap(tempMap, s.charAt(i - n));

            if (tempMap.equals(pMap)) {
                res.add(i - n + 1);
            }
        }
        return res;
    }
}