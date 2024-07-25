class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        auto lmd = [&](auto& a, auto& b) {
            return a < b;
        };
        priority_queue<int, vector<int>, decltype(lmd)> max_heap(lmd);
        
        for (int a : stones) max_heap.push(a);
        while (max_heap.size() > 1) {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();
            
            if (first == second) continue;
            max_heap.push(abs(first - second));
        }
        
        return max_heap.empty() ? 0 : max_heap.top();
    }
};