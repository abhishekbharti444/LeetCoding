class Solution {
public:
    int n;
    vector<int> parent;
    int getParent(int index) {
        if (parent[index] == index) return index;
        return parent[index] = getParent(parent[index]);
    }
    void unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        parent = vector<int> (n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (getParent(i) == getParent(graph[i][j])) return false;
                unionMethod(graph[i][0], graph[i][j]);
            }
        }
        return true;
    }
};