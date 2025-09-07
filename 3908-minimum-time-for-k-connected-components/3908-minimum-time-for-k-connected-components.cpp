class Solution {
public:
    /*
     * Approach: Binary Search + DFS
     * 
     * We binary search on the time t. For each candidate time:
     * 1. Remove all edges with time <= t from the graph
     * 2. Count connected components in the remaining graph using DFS
     * 3. If components >= k: try smaller t (search left)
     * 4. If components < k: try larger t (search right)
     * 
     * Key insight: As we increase t, more edges are removed, creating more components
     * 
     * Time: O(log(maxTime) * (V + E))
     * Space: O(V + E)
     */
    
    unordered_map<int, vector<pair<int, int>>> g;
    int n;
    
    void dfsUtil(int node, vector<bool>& vis, int tm) {
        if (vis[node]) return;
        vis[node] = true;
        for (auto [next_node, next_time]: g[node]) {
            // Only traverse edges that remain after removing edges with time <= tm
            if (vis[next_node] == false && next_time > tm) {
                dfsUtil(next_node, vis, tm);
            }
        }
    }
    
    bool getNumberOfComponents(int tm, int target_count) {
        vector<bool> vis(n, false);
        int count = 0;
        
        // Count connected components in graph after removing edges with time <= tm
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfsUtil(i, vis, tm);
                count++;
            }
        }
        
        return count >= target_count;
    }
    
    int minTime(int n, vector<vector<int>>& edges, int k) {
        this->n = n;
        
        // Build adjacency list and find max time for binary search range
        int low = 0;
        int high = 0;
        for (auto& edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
            high = max(high, edge[2]);
        }
        
        int res = -1;
        
        // Binary search on time t
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (getNumberOfComponents(mid, k)) {
                res = mid;
                high = mid - 1; // Try smaller time
            }
            else {
                low = mid + 1; // Try larger time
            }
        }
        
        return res;
    }
};
