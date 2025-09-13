/*
APPROACH: DFS with Greedy Path Score Equalization
1. For each node, recursively compute maximum path scores from all children
2. To equalize all paths, increase costs of nodes on shorter paths
3. At each internal node, find the maximum child path score
4. Count how many children have smaller scores (need cost increases)
5. Return current node's contribution: max_child_score + current_node_cost
Time: O(n), Space: O(n)
*/

class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<int> c;
    int n;
    int res = 0;
    
    long long dfsUtil(int node, int parent) {
        // Collect path scores from all children
        vector<long long> childScores;
        for (auto& child : g[node]) {
            if (child == parent) continue;  // Skip parent to avoid cycles
            childScores.push_back(dfsUtil(child, node));
        }

        // Base case: leaf node - return its own cost
        if (childScores.size() == 0) return c[node];

        // Find maximum path score among all children
        long long maxChildScore = *max_element(childScores.begin(), childScores.end());
        
        // Count nodes that need cost increases (children with smaller scores)
        for (auto score : childScores) {
            if (maxChildScore > score) {
                res++;  // This child's path needs cost increase
            }
        }
        
        // Return this node's contribution to parent's path score
        return maxChildScore + c[node];
    }
    
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        c = cost;
        this->n = n;
        
        // Build adjacency list for the tree
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfsUtil(0, -1);  // Start DFS from root with no parent
        return res;
    }
};
