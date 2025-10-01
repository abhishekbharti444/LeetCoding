class Solution {
    int[][] dp = new int[501][501];
    int n;

    /*
    https://leetcode.com/problems/burst-balloons/solutions/892552/for-those-who-are-not-able-to-understand-any-solution-with-diagram/
    */
    public int util(int[] nums, int i, int j) {
        if (i > j) return 0;
        if (i == j) {
            int temp = nums[i];
            if (i >= 1) temp *= nums[i-1];
            if (i < n-1) temp *= nums[i+1];
            return temp;
        }
        if (dp[i][j] != 0) return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; ++k) {
            int temp = nums[k];
            if (j + 1 < n) temp *= nums[j+1];
            if (i - 1 >= 0) temp *= nums[i-1];

            temp += util(nums, i, k-1) + util(nums, k+1, j);
            ans = Math.max(ans, temp);
        }
        return dp[i][j] = ans;
    }
    public int maxCoins(int[] arr) {
        n = arr.length;
        int[] nums = new int[n + 2];
        nums[0] = 1;
        for (int i = 0; i < n; ++i) {
            nums[i+1] = arr[i];
        } 
        nums[n+1] = 1;
        n = nums.length;
        return util(nums, 1, n-2);
    }
}