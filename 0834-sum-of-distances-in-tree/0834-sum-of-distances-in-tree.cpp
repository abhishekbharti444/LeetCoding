class Solution {
public:
        /*
        Look at the lee215's solution directly 
            https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)
            
        
        Brute force easy but O(N) will require us to rerooting the tree.
            
    */
    int total_nodes;
    vector<unordered_set<int>> tree;
    vector<int> res, count;
    void dfs1(int root, int parent) {
        for (int i : tree[root]) {
            if (i == parent) continue;
            dfs1(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }
    
    void dfs2(int root, int parent) {
        for (int i : tree[root]) {
            if (i == parent) continue;
            res[i] = res[root] - count[i] + total_nodes - count[i];
            dfs2(i, root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int edge_len = edges.size();
        total_nodes = n;
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);
        for (int i = 0; i < edge_len; ++i) {
            tree[edges[i][0]].insert(edges[i][1]);
            tree[edges[i][1]].insert(edges[i][0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
        
};