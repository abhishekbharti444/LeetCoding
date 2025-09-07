class Solution {
public:
    vector<int> parent;
    int getParent(int a) {
        if (a == parent[a]) return a;
        return parent[a] = getParent(parent[a]);
    }
    void unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa < pb) {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        for (int i = 0; i <= c; ++i) parent[i] = i;
        vector<set<int>> vec(c + 1);
        int con_len = connections.size();
        for (int i = 0; i < con_len; ++i) {
            unionMethod(connections[i][0], connections[i][1]);
        }
        for (int i = 0; i <= c; ++i) vec[getParent(i)].insert(i);
        vector<int> res;
        for (auto query: queries) {
            if (query[0] == 1) {
                int val = getParent(query[1]);
                if (vec[val].empty()) res.push_back(-1);
                else if (vec[val].find(query[1]) != vec[val].end()) res.push_back(query[1]);
                else res.push_back(*vec[val].begin());
            }
            else {
                int val = getParent(query[1]);
                if (vec[val].find(query[1]) != vec[val].end()) {
                    vec[val].erase(vec[val].find(query[1]));
                }
            }
        }
        return res;
    }
};