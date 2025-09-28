class Solution {
    public boolean checkTraingle(int a, int b, int c) {
        return a + b > c && b + c > a && a + c > b;
    }
    public int largestPerimeter(int[] nums) {
        int len = nums.length;
        int ans = 0;
        Arrays.sort(nums);
        for (int i = len-1; i >= 2; --i) {
            if (checkTraingle(nums[i], nums[i-1], nums[i-2])) 
                return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
}