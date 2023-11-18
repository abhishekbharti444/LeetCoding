class Solution {
public:
    vector<int> parent;
    int getParent(int index) {
        if (parent[index] == index) return index;
        return parent[index] = getParent(parent[index]);
    }
    void unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa == pb) {
            parent[pa] = pb;
        }
        else if (pa < pb) {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent = vector<int> (n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                }
                else {
                    unionMethod(i, mp[accounts[i][j]]);
                }
            }
        }
        
        map<int, vector<int>> map1;
        for (int i = 0; i < n; ++i) {
            map1[getParent(parent[i])].push_back(i);
            
        }
        vector<vector<string>> res;
        int ind = 0;
        for (auto& el : map1) {
            int index = el.first;
            unordered_set<string> s;
            for (int i = 0; i < el.second.size(); ++i) {
                for (int j = 1; j < accounts[el.second[i]].size(); ++j)
                    s.insert(accounts[el.second[i]][j]);
            }
            vector<string> ans;
            ans.push_back(accounts[el.first][0]);
            for (auto& a : s) ans.push_back(a);
            sort(ans.begin() + 1, ans.end());
            res.push_back(ans);
        }
        return res;
    }
};