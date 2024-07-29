class Solution {
public:
    
    vector<bool> vis;
    vector<bool> curr;
    
    int n; 
    vector<vector<int>> pre;
    unordered_map<int, vector<int>> g;
    
    
    bool util(int index) {
        if (curr[index]) return false;
        if (vis[index]) return true;
        
        vis[index] = true;
        curr[index] = true;
        bool res = true;
        for (auto& a : g[index]) {
            res = res && util(a);
        }
        curr[index] = false;
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        pre = prerequisites;
        vis = vector<bool> (n, false);
        curr = vis;
        for (int i = 0; i < pre.size(); i++) {
            g[pre[i][1]].push_back(pre[i][0]);
        }
        for (int i = 0; i < n; ++i) {
            // vis = vector<bool> (n, false); 
            if (!util(i)) return false;
        }
        return true;
    }
};