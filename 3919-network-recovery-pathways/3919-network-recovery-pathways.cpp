class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> fullGraph;  // Precomputed graph
    
    long long dijkstra(int minCost, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            if (u == n - 1) return d;

            for (auto [v, cost] : fullGraph[u]) {
                if (cost < minCost) continue;  // Skip edges below threshold
                if (dist[v] > d + cost) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return LLONG_MAX;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        fullGraph.resize(n);
        
        // Build graph ONCE with all valid edges
        int maxCost = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if (online[u] && online[v]) {
                fullGraph[u].push_back({v, cost});
                maxCost = max(maxCost, cost);
            }
        }
        
        int low = 0, high = maxCost, ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // No graph rebuilding - just pass threshold to dijkstra
            if (dijkstra(mid, k) <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
