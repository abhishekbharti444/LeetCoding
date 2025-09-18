class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<int> curr, vis;
    int n;
    bool util(int node) {
        if (curr[node] == 1) return false;
        if (vis[node] == 1) return true;

        curr[node] = 1;
        vis[node] = 1;
        for (int i = 0; i < g[node].size(); ++i) {
            if (util(g[node][i]) == false) return false;
        }
        curr[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        n = numCourses;
        curr.resize(n, 0);
        vis.resize(n, 0);
        for (int i = 0; i < pre.size(); ++i) {
            g[pre[i][1]].push_back(pre[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (util(i) == false) return false;
        }
        return true;
    }
};