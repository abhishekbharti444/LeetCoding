class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int r = 0;
        int c = 0;
        int x = m - 1;
        int y = n - 1;
        vector<int> res;
        while (r <= x && c <= y) {
            int i = r;
            int j = c;
            for (j = c; j <= y; j++) {
                res.push_back(mat[i][j]);
            }
            j = y;
            for (i = r+1; i <= x; ++i) res.push_back(mat[i][j]);
            i = x;
            if (r < x)
                for (j = y-1; j >= c; j--) res.push_back(mat[i][j]);
            j = c;
            if (c < y)
                for (i = x-1; i > r; --i) res.push_back(mat[i][j]);

            r++;
            c++;
            x--;
            y--;
        }
        return res;
    }
};