class Solution {
public:
    
    vector<int> parent;
    int n;
    int getParent(int index) {
        if (index == parent[index]) return index;
        return getParent(parent[index]);
    }
    bool unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa == pb) return true;
        else if (pa < pb) {
            parent[pb] = pa;
        }
        else {
            parent[pa] = pb;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        parent = vector<int> (n+1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        vector<int> res;
        for (int i = 0; i < edges.size(); ++i) {
            if (unionMethod(edges[i][0], edges[i][1])) {
                res = edges[i];
            }
        }
        return res;
    }
};