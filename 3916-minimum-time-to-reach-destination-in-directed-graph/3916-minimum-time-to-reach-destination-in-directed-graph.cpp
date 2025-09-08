/*
SOLUTION APPROACH: Modified Dijkstra for Time-Dependent Graph

PROBLEM: Find minimum time to reach node n-1 from node 0, where:
- Each edge has time window [start, end] when it can be used
- Can wait at current node or travel if edge is available
- Travel takes 1 unit of time

KEY INSIGHT: Use Dijkstra with time-based states
- State: (current_time, current_node)
- Greedy property holds: first time we reach a node is optimal for that node
- Time constraint: can only use edge if current_time is within [start, end]

ALGORITHM:
1. Use min-heap prioritized by time (earliest first)
2. For each node, explore all outgoing edges
3. For each edge: wait until start time if needed, then travel (+1 time)
4. Use visited array since first arrival at any node is optimal

EDGE USAGE LOGIC:
- If current_time > end: edge expired, skip
- If current_time < start: wait until start, then travel
- If start ≤ current_time ≤ end: travel immediately
- Travel time: max(start, current_time) + 1
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        // Build adjacency list: node -> [(next_node, start_time, end_time)]
        unordered_map<int, vector<vector<int>>> g;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            g[u].push_back({v, start, end});
        }
        
        // Edge case: already at destination
        if (n == 1) return 0;
        
        // Dijkstra setup: min-heap with (time, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        vector<bool> visited(n, false);
        
        min_heap.push({0, 0}); // Start at node 0 at time 0
        
        while (!min_heap.empty()) {
            auto [current_time, node] = min_heap.top();
            min_heap.pop();
            
            // Early termination: reached destination
            if (node == n - 1) return current_time;
            
            // Skip if already processed (first arrival is optimal)
            if (visited[node]) continue;
            visited[node] = true;
            
            // Explore all outgoing edges from current node
            for (auto& edge_info : g[node]) {
                int next_node = edge_info[0];
                int start_time = edge_info[1];
                int end_time = edge_info[2];
                
                // Skip if edge has expired
                if (end_time < current_time) continue;
                
                // Calculate arrival time at next node
                // Wait until edge becomes available, then travel (takes 1 unit)
                int arrival_time = max(start_time, current_time) + 1;
                
                // Add to queue if next node not yet visited
                if (!visited[next_node]) {
                    min_heap.push({arrival_time, next_node});
                }
            }
        }
        
        return -1; // No path found
    }
};
