class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        if (n==1) {
            return {0};
        }
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        for (auto& el : graph) {
            if (el.second.size() == 1) {
                q.push(el.first);
            }
        }
        
        while (n > 2) {
            int k = q.size();
            while (k--) {
                int elem = q.front();
                q.pop();
                int parent = *graph[elem].begin();
                graph.erase(elem);
                graph[parent].erase(elem);

                if (graph[parent].size() == 1) {
                    q.push(parent);
                }
                n--;
            }
        }
        vector<int> res;
        for (auto& el : graph) {
            res.push_back(el.first);
        }
        return res;
    }
};