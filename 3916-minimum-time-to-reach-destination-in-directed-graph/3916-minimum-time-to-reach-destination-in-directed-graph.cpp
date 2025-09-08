class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> g;
        if (n == 1) return 0;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        min_heap.push({0, 0}); // {time, node}

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int st = edges[i][2];
            int en = edges[i][3];
            g[u].push_back({v, st, en});
        }   
        vector<bool> vis(n, false);
        while (!min_heap.empty()) {
            auto [t, node] = min_heap.top();
            min_heap.pop();
            if (node == n-1) return t;
            if (vis[node]) continue;
            vis[node] = true;
            for (int i = 0; i < g[node].size(); ++i) {
                int next_node = g[node][i][0];
                int start = g[node][i][1];
                int end = g[node][i][2];
                if (end < t) continue;
                int curr_time = max(start, t) + 1;
                if (!vis[next_node]) min_heap.push({curr_time, next_node});
            }
        }
        return -1;


    }
};