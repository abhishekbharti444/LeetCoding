class Solution {
public:
    int n;
    vector<vector<int>> cache;
    int util(int curr, int clip) {
        if (curr >= n) {
            if (curr == n) return 0;
            return 10001;
        }
        return min(util(curr + clip, clip) + 1, util(curr + curr, curr) + 2);
    }
    int minSteps(int n) {
        this->n = n;
        if (n == 1) return 0;
        return 1 + util(1, 1);     
    }
};