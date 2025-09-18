/*
Approach: Topological Sort (Kahn's Algorithm)
1. Build directed graph where edge exists from smaller to larger adjacent values
2. Calculate indegree for each cell (number of smaller neighbors pointing to it)
3. Start BFS from cells with indegree 0 (local minima)
4. Process level by level, decrementing indegrees of larger neighbors
5. Number of levels processed = longest increasing path length
*/

class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Calculate indegree for each cell
        vector<vector<int>> indeg(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int r = i + dx[k];
                    int c = j + dy[k];
                    // If neighbor is larger, it has incoming edge from current cell
                    if (isValid(r, c, m, n) && mat[r][c] > mat[i][j]) {
                        indeg[r][c]++;
                    }
                }
            }
        }

        // Start from cells with indegree 0 (local minima)
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indeg[i][j] == 0) q.push({i, j});
            }
        }
        
        int levels = 0;
        // Process level by level
        while (!q.empty()) {
            int size = q.size();
            levels++; // Each level represents one step in the longest path
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                // Check all 4 neighbors
                for (int k = 0; k < 4; k++) {
                    int r = x + dx[k];
                    int c = y + dy[k];
                    // If neighbor is larger, decrement its indegree
                    if (isValid(r, c, m, n) && mat[r][c] > mat[x][y]) {
                        indeg[r][c]--;
                        // If indegree becomes 0, add to queue
                        if (indeg[r][c] == 0) q.push({r, c});
                    }
                }
            }
        }
        return levels;
    }
};
