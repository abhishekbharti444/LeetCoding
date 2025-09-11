class Solution {
public:
    vector<int> parent;
    int getParent(int index) {
        if (index == parent[index]) return index;
        return parent[index] = getParent(parent[index]);
    }
    bool unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa == pb) return false;
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> wts;
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        int res = INT_MAX;
        int edge_count = 0;
        // Process must edges first;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][3] == 1) {
                if (getParent(edges[i][0]) == getParent(edges[i][1])) return -1;
                unionMethod(edges[i][0], edges[i][1]);
                edge_count++;
                res = min(res, edges[i][2]);
            }
        }

        // Sort the edges descending based on strength
        auto lmd = [&](auto& a, auto& b) {
            return a[2] > b[2];
        };
        sort(edges.begin(), edges.end(), lmd);
        // Process non must edges next
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];
            if (m == 1) continue;
            if (getParent(u) == getParent(v)) continue;
            unionMethod(u, v);
            edge_count++;
            wts.push_back(s);
        }
        if (edge_count != n-1) return -1;
        sort(wts.begin(), wts.end());
        int len = wts.size();
        int index = 0;
        while (index < len && index < k) {
            res = min(res, 2*wts[index]);
            index++;
        }
        while (index < len) {
            res = min(res, wts[index]);
            index++;
        }
        return res == INT_MAX ? -1 : res;

    }
};