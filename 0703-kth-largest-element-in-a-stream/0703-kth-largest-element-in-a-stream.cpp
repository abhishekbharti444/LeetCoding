class KthLargest {
public:
    int k;
    vector<int> vec;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        vec = nums;
        for (int a : vec) {
            min_heap.push(a);
            if (min_heap.size() > k) min_heap.pop();
        }
    }
    
    int add(int val) {
        if (min_heap.size() < k) {
            min_heap.push(val);
            return min_heap.top();
        }
        if (val < min_heap.top()) return min_heap.top();
        min_heap.push(val);
        if (min_heap.size() > k) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */