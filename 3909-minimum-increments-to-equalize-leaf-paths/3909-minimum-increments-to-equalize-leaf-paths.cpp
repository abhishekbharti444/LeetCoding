class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<int> c;
    int n;
    int res = 0;
    long long dfsUtil(int node, int parent) {
        
        vector<long long> score;
        for (auto& next: g[node]) {
            if (next == parent) continue;
            score.push_back(dfsUtil(next, node));
        }

        if (score.size() == 0) return c[node];

        long long child_max = *max_element(score.begin(), score.end());
        for (auto el: score) {
            if (child_max > el) {
                res++;
            }
        }
        return child_max + c[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        c = cost;
        this->n = n;
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfsUtil(0, -1);
        return res;
    }
};