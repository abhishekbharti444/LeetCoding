class Solution {
public:
    /*
        Approach:
            1. For the weight of digging the wells, consider a virtual node(in this case 0 is taken) and 
        connect each of the node(house) with this vNode.
            2. The weight of edges to connect pipes is given in the input. 
            3. Now the question is reduced to finding the MST of this graph.
            4. Kruskal algo:(Union Find implementation)
                a. Sort all the edges given by weight.
                b. Include an edge and check if that creates a cycle. Do a call to unionMethod and if parents are equal, this edge will cause a cycle, so don't add this in the MST.
            
        Time: 
            ElogV
    */
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