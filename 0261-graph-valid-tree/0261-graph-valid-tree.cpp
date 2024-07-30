class Solution {
public:
    
    /*
        Great question. Only difference from course schedule is that the graph is bidirectional. 
        Approach: 
            1. If the edge count is not n-1, return false;
            2. Check for the cycle with top sort
                2a. Since the graph is bidirectional, push both nodes of the edge in graph. 
                2b. To handle the cases where you might be trying to visit the same node as prev, introduce a pre node which is the node you have called your next recursion.
                2c. The condition a==pre will take care of not traversing the same node again from where you came. 
            3. If no cycle was found, this is a valid tree.
    */
    int n;
    unordered_map<int, vector<int>> g;
    vector<bool> curr, vis;
    bool util(int index, int pre) {
        if (curr[index]) return false;
        if (vis[index]) return true;
        vis[index] = true;
        curr[index] = true;
        bool res_flag = true;
        
        for (auto& a : g[index]) {
            if (a == pre) continue;
            res_flag = res_flag && util(a, index);
        }
        
        curr[index] = false;
        return res_flag;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        if (n != edges.size() + 1) return false;
        for (int i = 0; i < edges.size(); ++i) {
            g[edges[i][1]].push_back(edges[i][0]);
            g[edges[i][0]].push_back(edges[i][1]);
        }
        vis = vector<bool> (n, false);
        curr = vis;
        for (int i = 0; i < n; ++i) {
            if (!util(i, -1)) return false;
        }
        
        return true;
        
    }
};