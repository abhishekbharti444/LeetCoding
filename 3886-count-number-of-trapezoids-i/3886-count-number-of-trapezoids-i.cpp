class Solution {
public:
    const int mod = 1e9 + 7;
    long long calculateNC2(int n) {
        return ((long long)n * (n -1))/2;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int res = 0;
        int count = 0;
        unordered_map<int, int> umap;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            umap[points[i][1]]++;
        }
        for (auto el: umap) {
            long long nc2 = calculateNC2(el.second);
            res = (res + count * nc2) % mod;
            count = (count + nc2) % mod;
        }
        return res;
    }
};