class Solution {
public:
    struct data {
        int u, v, w;
    };
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
    
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<data> vec;
        
        parent = vector<int> (n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
        
        for (int i = 0; i < pipes.size(); ++i) {
            vec.push_back({pipes[i][0], pipes[i][1], pipes[i][2]});
        }
        for (int i = 0; i < wells.size(); ++i) {
            vec.push_back({0, i + 1, wells[i]});
        }
        
        auto lmd = [&](auto& a, auto& b){
            return a.w < b.w;
        };
        sort(vec.begin(), vec.end(), lmd);
        int res = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (unionMethod(vec[i].u, vec[i].v)) res += vec[i].w;
        }
        return res;
    }
    
};