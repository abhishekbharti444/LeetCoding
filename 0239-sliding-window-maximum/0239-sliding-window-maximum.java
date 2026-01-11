class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        
        Deque<Integer> dq = new ArrayDeque<>();
        int[] res = new int[n - k + 1];
        for (int i = 0; i < k; ++i) {
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }
            dq.addLast(i);
        }
        int index = 0;
        res[index] = nums[dq.peekFirst()];
        index++;
        for (int i = k; i < n; ++i) {
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) {
                dq.pollLast();
            }
            while (!dq.isEmpty() && i - dq.peekFirst() >= k) {
                dq.pollFirst();
            }
            dq.addLast(i);

            res[index] = nums[dq.peekFirst()];
            index++;
        }
        return res;
    }
}