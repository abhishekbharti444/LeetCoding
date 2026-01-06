class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n-1;
        Arrays.sort(nums);

        int minDiff = Integer.MAX_VALUE;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int start = i + 1;
            int end = n-1;

            while (start < end) {
                int currSum = nums[i] + nums[start] + nums[end];
                if (Math.abs(currSum - target) < minDiff) {
                    minDiff = Math.abs(currSum - target);
                    res = currSum;
                }
                if (currSum < target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return res;
    }
}