class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> graph;
        int res = -1;
        int max_edges = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u] += 1;
            graph[v] += 1;
            
            // cout<<graph[u]<<endl;
            if (max_edges < graph[u]) {
                max_edges = graph[u];
                res = u;
            }
            if (max_edges < graph[v]) {
                max_edges = graph[v];
                res = v;
            }
        }
        // cout<<max_edges<<endl;
        return res;
    }
};