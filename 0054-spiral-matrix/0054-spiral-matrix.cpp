class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) res.push_back(mat[top][j]);
            top++;
            for (int i = top; i <= bottom; ++i) res.push_back(mat[i][right]);
            right--;
            if (top > bottom || left > right) break;
            for (int j = right; j >= left; --j) res.push_back(mat[bottom][j]);
            bottom--;
            for (int i = bottom; i >= top; --i) res.push_back(mat[i][left]);
            left++;
        }
        return res;
    }
};