class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        // Run loop only for 
        for (int i = 0; i < len - 2; ++i) {

            int start = i + 1;
            int end = len - 1; 
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] == 0) {
                    res.add(Arrays.asList(nums[i], nums[start], nums[end]));
                    // Handle inside of {start, end} as well because they could also be duplicates. 
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                }
                else if (nums[i] + nums[start] + nums[end] > 0) {
                    end--;
                }
                else {
                    start++;
                }
            }

            // To be able to remove the duplicates, we should post process the i and skip for the same next element.
            // If we pre process this, then we will lose the first occurence of that i itself. 
            while (i < len-1 && nums[i] == nums[i+1]) {
                i++;
            }
        }
        return res;
    }
}