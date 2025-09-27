class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        // Create dp table with same structure as triangle
        List<List<Integer>> dp = new ArrayList<>(Collections.nCopies(n, null));

        // Process from bottom to top
        for (int i = n-1; i >= 0; --i) {
            int len = triangle.get(i).size();
            // Copy current row from triangle to dp
            dp.set(i, new ArrayList<Integer>(triangle.get(i)));

            for (int j = 0; j < len; ++j) {
                // Base case: bottom row stays as is
                if (i == n-1) continue;

                // Two possible paths from current position
                int curr = dp.get(i + 1).get(j);     // Path to (i+1, j)
                int right = dp.get(i + 1).get(j + 1); // Path to (i+1, j+1)

                // Update dp with minimum path sum
                int minVal = dp.get(i).get(j) + Math.min(curr, right);
                dp.get(i).set(j, minVal);
            }
        }

        // Return minimum path sum from top
        return dp.get(0).get(0);
    }
}