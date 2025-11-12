class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int m = words.length;
        int n = queries.length;

        int[] pre = new int[m+1];
        int[] res = new int[n];
        int[] req = new int[m];

        for (int i = 0; i < m; ++i) {
            int first = 0;
            int last = words[i].length() - 1;
            if ("aeiou".indexOf(words[i].charAt(first)) != -1 && "aeiou".indexOf(words[i].charAt(last)) != -1) {
                req[i] = 1;
            }
            if (i == 0) {
                // pre[i] = req[i];
                pre[i+1] = req[i];
            }
            else pre[i+1] = req[i] + pre[i];
        }

        for (int i = 0; i < n; ++i) {
            res[i] = pre[queries[i][1]+1] - pre[queries[i][0]];
        }
        return res;

    }
}