class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        List<List<Integer>> dp = new ArrayList<>(Collections.nCopies(n, null));

        for (int i = n-1; i >= 0; --i) {
            int len = triangle.get(i).size();
            dp.set(i, new ArrayList<Integer>(triangle.get(i)));

            for (int j = 0; j < len; ++j) {
                if (i == n-1) continue;
                int curr = 0;
                int right = 0;
                right = dp.get(i + 1).get(j + 1);
                curr = dp.get(i + 1).get(j);
                int minVal = dp.get(i).get(j) + Math.min(right, curr);
                dp.get(i).set(j, minVal);
            }
        }
        return dp.get(0).get(0);
    }
}