#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    
    
    /*
        Solved it myself without any hints. Just saw the related topics as Binary Search
        
        Approach: 
        1. To get the minimum value with which we can traverse from 0, 0 to m-1, n-1 we have to find a path which satisfies that.
        2. We can get the low value as the minimum of the matrix and high as the maximum of the matrix. 
        3. We can choose a mid with which we can check if reachability from 0, 0 to m-1, n-1 is possible or not. 
        4. For each mid value we apply a dfs from 0, 0 and check if we reach m-1, n-1. If yes, capture that value as a potential result and try to further optimize it by making high to mid-1. If not make the low as mid + 1 to check for a higher value. 
        
        Time: O(N^2 log(max_val));
    */
    
    vvi g;
    int m, n;
    vvi vis;
    vi dx = {0, 0, 1, -1};
    vi dy = {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return x < m && y < n && x >= 0 && y >= 0;
    }
    bool util(int x, int y, int val) {
        if (!isValid(x, y) || vis[x][y] == 1 || g[x][y] > val) return false;
        if (x == m-1 && y == n-1) return true;
        vis[x][y] = 1;
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            res = util(x + dx[i], y + dy[i], val) || res;
        }
        return res;
    }
    bool check(int val) {
        vis = vvi (m, vi(n, 0));
        return util(0, 0, val);
    }
    int swimInWater(vector<vector<int>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                low = min(low, g[i][j]);
                high = max(high, g[i][j]);
            }
        }
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            
            if (check(mid)) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};