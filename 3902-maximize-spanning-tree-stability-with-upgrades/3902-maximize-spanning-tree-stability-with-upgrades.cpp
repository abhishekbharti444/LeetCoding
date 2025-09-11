/*
APPROACH: Two-Phase Greedy + Union Find + Optimal Upgrades
1. Phase 1: Process all must edges first (forced choices)
2. Phase 2: Greedily select optional edges by strength descending
3. Phase 3: Apply upgrades optimally to k smallest selected weights
4. Return minimum strength among all final edges in spanning tree
Time: O(E log E), Space: O(N + E)
*/

class Solution {
public:
    vector<int> parent;
    
    int getParent(int index) {
        if (index == parent[index]) return index;
        return parent[index] = getParent(parent[index]); // Path compression
    }
    
    bool unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa == pb) return false; // Already connected
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i; // Initialize DSU
        
        vector<int> optionalWeights;
        int minStrength = INT_MAX;
        int edgesUsed = 0;
        
        // Phase 1: Process must edges (no choice - add all or fail)
        for (auto& edge : edges) {
            if (edge[3] == 1) { // Must edge
                if (getParent(edge[0]) == getParent(edge[1])) return -1; // Cycle with must edge
                unionMethod(edge[0], edge[1]);
                edgesUsed++;
                minStrength = min(minStrength, edge[2]);
            }
        }

        // Phase 2: Greedy selection of optional edges by strength descending
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] > b[2]; // Higher strength first
        });
        
        for (auto& edge : edges) {
            if (edge[3] == 1) continue; // Skip must edges (already processed)
            if (getParent(edge[0]) == getParent(edge[1])) continue; // Skip if creates cycle
            
            unionMethod(edge[0], edge[1]);
            edgesUsed++;
            optionalWeights.push_back(edge[2]);
        }
        
        // Check if spanning tree is possible
        if (edgesUsed != n - 1) return -1;
        
        // Phase 3: Apply upgrades optimally to k smallest optional weights
        sort(optionalWeights.begin(), optionalWeights.end()); // Sort ascending for optimal upgrades
        
        int index = 0;
        // Process upgraded weights (k smallest get doubled)
        while (index < optionalWeights.size() && index < k) {
            minStrength = min(minStrength, 2 * optionalWeights[index]);
            index++;
        }
        // Process remaining unupgraded weights
        while (index < optionalWeights.size()) {
            minStrength = min(minStrength, optionalWeights[index]);
            index++;
        }
        
        return minStrength == INT_MAX ? -1 : minStrength;
    }
};
