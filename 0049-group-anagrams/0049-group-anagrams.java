class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        HashMap<String, ArrayList<String>> mp = new HashMap<>();
        for (String str: strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String sortedStr = String.valueOf(arr);
            if (!mp.containsKey(sortedStr)) {
                mp.put(sortedStr, new ArrayList<>());
            }
            mp.get(sortedStr).add(str);
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, ArrayList<String>> entry: mp.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }
}