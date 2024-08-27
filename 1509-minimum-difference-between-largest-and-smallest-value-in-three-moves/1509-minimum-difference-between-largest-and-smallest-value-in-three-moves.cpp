class Solution {
public:
    int minDifference(vector<int>& nums) {
        int res = INT_MAX;
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        priority_queue<int> max_heap;
        
        int n = nums.size();
        if (n <= 3) return 0;

        for (int i = 0; i < n; ++i) {
            min_heap.push(nums[i]);
            max_heap.push(nums[i]);
            if (max_heap.size() > 4) max_heap.pop();
            if (min_heap.size() > 4) min_heap.pop();
        }
        
        priority_queue<int, vector<int>, greater<int>> new_heap;
        while (!max_heap.empty()) {
            new_heap.push(max_heap.top());
            max_heap.pop();
        }

        while (!new_heap.empty()) {
            res = min(res, abs(new_heap.top() - min_heap.top()));
            new_heap.pop();
            min_heap.pop();
        }
        return res;
    }
};