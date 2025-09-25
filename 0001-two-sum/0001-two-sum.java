class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();

        int len = nums.length;
        for (int i = 0; i < len; ++i) {
            
            if (mp.containsKey(target - nums[i])) {
                return new int[]{mp.get(target - nums[i]), i};
            }
            mp.put(nums[i], i);
        }
        return null;
    }
}