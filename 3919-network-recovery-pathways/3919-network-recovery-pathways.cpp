/*
SOLUTION APPROACH: Binary Search + Dijkstra for Maximum Bottleneck Path

PROBLEM: Find path from 0 to n-1 where:
1. Total cost ≤ k
2. All intermediate nodes are online  
3. Maximize the minimum edge cost on the path (bottleneck optimization)

KEY INSIGHT: Binary search on the answer (minimum edge threshold)
- For threshold T: "Can we find a path using only edges ≥ T with total cost ≤ k?"
- Higher T = more restrictive = fewer available edges
- We want the maximum T that still allows a valid path

ALGORITHM:
1. Build graph once with all valid edges (online nodes only)
2. Binary search on edge cost threshold [0, max_edge_cost]
3. For each threshold, run Dijkstra filtering edges < threshold
4. If shortest path ≤ k, try higher threshold; else try lower

OPTIMIZATION: Precompute graph once, filter during search
- Avoids expensive graph reconstruction in each binary search iteration
- Filter edges dynamically in Dijkstra based on current threshold
*/

class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> graph;  // Precomputed graph: node -> [(neighbor, cost)]
    
    // Modified Dijkstra: only use edges with cost >= minCost
    long long dijkstra(int minCost) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        // Min-heap: (distance, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip if we've found a better path to this node
            if (d > dist[u]) continue;
            
            // Early termination: reached destination
            if (u == n - 1) return d;

            // Explore neighbors
            for (auto [v, cost] : graph[u]) {
                // Filter: only use edges with cost >= minCost (bottleneck constraint)
                if (cost < minCost) continue;
                
                // Standard Dijkstra relaxation
                if (dist[v] > d + cost) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return LLONG_MAX;  // No path found
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        graph.resize(n);
        
        // Build graph once: include only edges between online nodes
        int maxCost = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if (online[u] && online[v]) {
                graph[u].push_back({v, cost});
                maxCost = max(maxCost, cost);  // Track max edge cost for binary search range
            }
        }
        
        // Binary search on minimum edge cost threshold
        int low = 0, high = maxCost;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check: can we find path using only edges ≥ mid with total cost ≤ k?
            long long shortestPath = dijkstra(mid);
            
            if (shortestPath <= k) {
                // Valid path exists with threshold mid
                ans = mid;           // Update answer
                low = mid + 1;       // Try higher threshold (maximize bottleneck)
            } else {
                // No valid path with threshold mid
                high = mid - 1;      // Try lower threshold
            }
        }
        
        return ans;
    }
};
