class Solution {
public:

    unordered_map<int, vector<pair<int, int>>> g;
    long long k;
    int n;
    long long dijkstra(unordered_map<int, vector<pair<int, int>>>& g) {
        int source = 0;
        int target = n-1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;

        min_heap.push({0, source});

        while (min_heap.size() > 0) {
            auto top = min_heap.top();
            min_heap.pop();
            int u = top.second;
            int d = top.first;
            if (d > dist[u]) continue;
            if (u == target) return d;

            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].first;
                int wt = g[u][i].second;
                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    min_heap.push({dist[v], v});
                }
            }
        }
        return LLONG_MAX;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = 0;
        int high = 1e9;
        int ans = -1;
        n = online.size();
        while (low <= high) {
            int mid = low + (high - low)/2;

            unordered_map<int, vector<pair<int, int>>> g;
            g.clear();
            // Form the graph only for edges values >= mid && the nodes are online     
            for (int i = 0; i < edges.size(); ++i) {
                int u = edges[i][0];
                int v = edges[i][1];
                int cost = edges[i][2];
                if (cost >= mid && online[u] && online[v]) {
                    g[u].push_back({v, cost});
                }
            }
            long long score = dijkstra(g);
            if (score <= k) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;

            g.clear();
        }
        return ans;
    }
};