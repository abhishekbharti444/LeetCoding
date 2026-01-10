class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) continue;
            while (nums[i] != i + 1) {
                int temp = nums[i];
                int nextIndex = nums[i] - 1;
                if (nextIndex < 0 || nextIndex >= n) break;
                nums[i] = nums[nextIndex];
                nums[nextIndex] = temp;
                if (nums[i] < 0 || nums[i] >= n || nums[i] == temp) break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
            // if (nums[i] <= 0 || nums[i] > n || nums[i] < i + 1) return i + 1;
        }
        return n + 1;
    }
}