class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            q.offer(nums[i]);
        }
        while (q.size() > 1) {
            int k = q.size();
            int prev = q.poll();
            for (int i = 1; i < k; ++i) {
                int front = q.poll();
                int curr = (front + prev) % 10;
                prev = front;
                q.offer(curr);
            }
        }
        return q.peek();
    }
}