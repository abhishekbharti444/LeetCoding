class Solution {
public:
    struct data {
        int num;
        int freq;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        auto lmd = [&](auto& a, auto& b) {
            return a.freq > b.freq;
        };
        priority_queue<data, vector<data>, decltype(lmd)> max_heap(lmd);
        
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
        }
        
        for (auto& a : mp) {
            max_heap.push({a.first, a.second});
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }
        
        vector<int> res;
        
        while (max_heap.size() > 0) {
            res.push_back(max_heap.top().num);
            max_heap.pop();
        }
        return res;
    }
};