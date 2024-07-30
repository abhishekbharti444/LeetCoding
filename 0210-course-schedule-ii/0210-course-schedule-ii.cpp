class Solution {
public:
    
    vector<bool> vis;
    vector<bool> curr;
    int n;
    unordered_map<int, vector<int>> pre;
    stack<int> st;
    bool util(int index) {
        if (curr[index]) return false;
        if (vis[index]) return true;
        vis[index] = true;
        curr[index] = true;
        bool flag = true;
        for (auto& a : pre[index]) flag = flag && util(a);
        st.push(index);
        curr[index] = false;
        return flag;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int len = prerequisites.size();
        n = numCourses;
        for (int i = 0; i < len; ++i) pre[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vis = vector<bool> (n, false);
        curr = vector<bool> (n, false);
        
        for (int i = 0; i < n; ++i) {
            if (!util(i)) {
                return {};
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};