class Solution {
public:
    int findMinLastRowNonCurrCol(vector<int>& vec, int index) {
        int min_val = INT_MAX; 
        for (int i = 0; i < vec.size(); ++i) {
            if (i == index) continue;
            min_val = min(min_val, vec[i]);
        }
        return min_val;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> memo(m, vector<int> (n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j< n; ++j) {
                if (i == 0) {
                    memo[i][j] = grid[i][j];
                }
                else {
                    int last_row_min = findMinLastRowNonCurrCol(memo[i-1], j);
                    memo[i][j] = last_row_min + grid[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, memo[m-1][i]);
        }
        return res;
    }
};