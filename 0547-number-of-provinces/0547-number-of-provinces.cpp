class Solution {
public:
    vector<int> parent;
    int getParent(int index) {
        if (index == parent[index]) return index;
        return parent[index] = getParent(parent[index]);
    }
    void unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent = vector<int> (n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (isConnected[i][j] == 1) unionMethod(i, j);
            }
        }
        
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) st.insert(getParent(parent[i]));
        
        return st.size();
    }
};