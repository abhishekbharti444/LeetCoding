class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < n; ++i) {
            min_heap.push(nums[i]);
            if (min_heap.size() > k) min_heap.pop();
        }
        return min_heap.top();
    }
};