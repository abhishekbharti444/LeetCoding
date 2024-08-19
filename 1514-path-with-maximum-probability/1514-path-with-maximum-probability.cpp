class Solution {
public:
    // const int INF = 1e9 + 7;
    /*
        Approach: This problem is very similar to the problem network delay time. Follow the Dijkstra's algorithm and think how can you maximize the path probability by using the same algo. 
    */
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> g;
        
        for (int i = 0; i < edges.size(); ++i) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> dist_arr(n, 0.0);
        auto lmd = [&](auto& a, auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(lmd)> min_heap(lmd);
        
        dist_arr[start_node] = 1.0;
        
        min_heap.push({start_node, 1.0});
        
        while (!min_heap.empty()) {
            int curr_node = min_heap.top().first;
            min_heap.pop();
            for (auto& el: g[curr_node]) {
                int next_node = el.first;
                double next_wt = el.second;
                
                if (dist_arr[next_node] < next_wt * dist_arr[curr_node]) {
                    dist_arr[next_node] = next_wt * dist_arr[curr_node];
                    min_heap.push(el);
                }
            }
        }
        
        return dist_arr[end_node];
    }
};