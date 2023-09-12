class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        priority_queue<int> max_heap;
        for (auto& el: mp) max_heap.push(el.second);
        int res = 0;
        while (max_heap.size() > 1) {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            if (first == second) {
                if (first - 1 > 0) max_heap.push(first-1);
                res++;
            }
        }
        return res;
    }
};