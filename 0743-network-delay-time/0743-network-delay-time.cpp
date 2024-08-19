class Solution {
public:
    const int INF = 1e9 + 7;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // int n = times.size();
        unordered_map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < times.size(); ++i) {
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        auto lmd = [&](auto& a, auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lmd)> min_heap(lmd);
        
        min_heap.push({k, 0});
        vector<int> dist_arr(n + 1, INF);
        dist_arr[k] = 0;
        while (!min_heap.empty()) {
            auto curr_node = min_heap.top().first;
            min_heap.pop();
            for (auto& el:g[curr_node]) {
                int next_node = el.first;
                int next_wt = el.second;
                if (dist_arr[next_node] > next_wt + dist_arr[curr_node]) {
                    dist_arr[next_node] = next_wt + dist_arr[curr_node];
                    min_heap.push({next_node, next_wt});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res = max(res, dist_arr[i]);
        }
        return res==INF ? -1 : res;
    }
};