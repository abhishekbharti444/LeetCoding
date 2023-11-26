class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int edge_len = edges.size();
        unordered_map<int, int> in_mp, out_mp;
        for (int i = 0; i < edge_len; ++i) {
            out_mp[edges[i][0]]++;
            in_mp[edges[i][1]]++;
        }
        
        vector<int> res; 
        for (int i = 0; i < n; ++i) {
            if (in_mp.find(i) == in_mp.end()) res.push_back(i);
        }
        return res;
    }
};