class Solution {
public:
    /*
     * Approach: Binary Search + DFS
     * 
     * We binary search on the maximum edge weight allowed in any component.
     * For each candidate weight, we build a filtered graph containing only 
     * edges with weight ≤ candidate, then count connected components using DFS.
     * 
     * If components ≤ k: try smaller weight (search left)
     * If components > k: try larger weight (search right)
     * 
     * Time: O(log(maxWeight) * (V + E))
     * Space: O(V + E)
     */
    
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& vis, int maxWeight) {
        vis[node] = true;
        for (auto [neighbor, weight] : graph[node]) {
            if (!vis[neighbor] && weight <= maxWeight) {
                dfs(neighbor, graph, vis, maxWeight);
            }
        }
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // Build adjacency list once
        vector<vector<pair<int, int>>> graph(n);
        int low = 0, high = 0;
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
            high = max(high, edge[2]);
        }
        
        int result = -1;
        
        // Binary search on maximum edge weight
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<bool> vis(n, false);
            int components = 0;
            
            // Count connected components using edges ≤ mid
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    components++;
                    if (components > k) break; // Early termination
                    dfs(i, graph, vis, mid);
                }
            }
            
            if (components <= k) {
                result = mid;
                high = mid - 1; // Try smaller maximum weight
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};
