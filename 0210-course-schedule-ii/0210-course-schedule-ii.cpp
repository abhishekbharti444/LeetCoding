class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int n = numCourses;
        vector<int> indeg(n, 0);
        unordered_map<int, vector<int>> g;
        vector<int> res;
        for (int i = 0; i < prereq.size(); ++i) {
            g[prereq[i][1]].push_back(prereq[i][0]);
            indeg[prereq[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                int front = q.front();
                q.pop();
                res.push_back(front);
                count++;

                for (auto el: g[front]) {
                    indeg[el]--;
                    if (indeg[el] == 0) q.push(el);
                }
            }
        }
        if (count < n) return {};
        return res;
    }
};