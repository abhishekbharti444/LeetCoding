class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;

        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        int res = 0;
        int currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += nums[i];

            if (mp.containsKey(currSum - k)) {
                res += mp.get(currSum - k);
            }
            Integer prev = mp.getOrDefault(currSum, 0);
            mp.put(currSum, prev + 1);
        }
        return res;
    }
}