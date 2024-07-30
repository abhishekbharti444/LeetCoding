class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<bool> vis;
    void util(int index) {
        if (vis[index]) return;
        
        vis[index] = true;
        for (int a : g[index]) util(a);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vis = vector<bool> (n, false);
        
        for (int i = 0; i < edges.size(); ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                res++;
                util(i);
            }
        }
        return res;
    }
};