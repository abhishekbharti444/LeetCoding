class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> res = heights;
        sort(res.begin(), res.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += heights[i] != res[i] ? 1 : 0;
        }
        return ans;
    }
};