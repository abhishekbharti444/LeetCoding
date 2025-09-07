class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> g;
    int n;
    void dfsUtil(int node, vector<bool>& vis, int tm) {
        if (vis[node]) return;
        vis[node] = true;
        for (auto [next_node, next_time]: g[node]) {
            if (vis[next_node] == false && next_time > tm) {
                dfsUtil(next_node, vis, tm);
            }
        }
    }
    bool getNumberOfComponents(int tm, int target_count) {
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfsUtil(i, vis, tm);
                count++;
                if (count >= target_count) return true;
            }
        }
        return count >= target_count;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        this->n = n;
        int low = 0;
        int high = 0;
        for (auto edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
            high = max(high, edge[2]);
        }
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            bool check = getNumberOfComponents(mid, k);
            if (check) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};