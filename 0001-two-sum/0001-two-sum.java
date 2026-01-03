class Solution {
    public int[] twoSum(int[] nums, int target) {
        // 2. Algorithm Core
        int len = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < len; ++i) {
            if (mp.containsKey(target - nums[i])) {
                return new int[]{i, mp.get(target - nums[i])};
            }
            mp.put(nums[i], i);
        }

        return new int[0]; // Placeholder
    }
}