class Solution {
public:
    struct edge {
        int u,v,w;
    };
    vector<int> parent;
    int manDistance(int x1, int x2, int y1, int y2) {
        return abs(x2-x1) + abs(y2-y1);
    }
    int getParent(int index) {
        if (parent[index] == index) return index;
        return parent[index] = getParent(parent[index]);
    }
    bool unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        
        if (pa == pb) return true;
        
        if (pa < pb) {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
        return false;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent = vector<int> (n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        vector<edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({i, j, manDistance(points[i][0], points[j][0], points[i][1], points[j][1])});
            }
        }
        auto lmd = [&](auto& a, auto& b) {
            return a.w < b.w;
        };
        sort(edges.begin(), edges.end(), lmd);
        int res = 0;
        
        for (int i = 0; i < edges.size(); ++i) {
            if (unionMethod(edges[i].u, edges[i].v) == false) res += edges[i].w;
        }
        return res;
    }
};