class Solution {
public:
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