class Solution {
public:
    void connectedComponents(int node, vector<vector<pair<int, int>>>& g, vector<bool>& vis, int max_cost) {
        vis[node] = true;
        for (auto [next_node, next_wt] : g[node]) {
            if (vis[next_node] || next_wt > max_cost) continue;
            connectedComponents(next_node, g, vis, max_cost);
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // Form a graph(connect an edge in the graph) only when it has edge_cost <= mid which is max_cost for binary search

        int res = -1;

        int low = 0;
        int high = 0;

        vector<vector<pair<int, int>>> g(n);
        for (auto edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
            high = max(high, edge[2]);
        }

        while (low <= high) {
            int mid = low + (high - low)/2;
            int max_cost = mid;
            vector<bool> vis(n, false);
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) {
                    count++;
                    if (count > k) break;
                    connectedComponents(i, g, vis, max_cost);
                }
            }


            if (count <= k) {
                high = mid - 1;
                res = mid;
            }
            else low = mid + 1;
        }
        return res;
    }
};