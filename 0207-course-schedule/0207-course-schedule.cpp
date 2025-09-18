class Solution {
public:
    vector<int> curr, vis;
    int n;
    unordered_map<int, vector<int>> g;
    bool dfsUtil(int node) {
        if (curr[node] == 1) return false;
        if (vis[node] == 1) return true;
        vis[node] = 1;
        curr[node] = 1;
        bool res = true;
        for (int i = 0; i < g[node].size(); ++i) {
            res = res && dfsUtil(g[node][i]);
        }
        curr[node] = 0;
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        n = numCourses;
        for (int i = 0; i < pre.size(); ++i) {
            g[pre[i][0]].push_back(pre[i][1]);
        }

        curr.resize(n, 0);
        vis.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0 && !dfsUtil(i)) {
                return false;
            }
        }
        return true;
    }
};