class Solution {
public:
    /*
     * Approach: Union-Find + Set for Online Station Tracking
     * 
     * 1. Use Union-Find to group stations into power grids (connected components)
     * 2. Maintain sets of online stations for each grid component
     * 3. For maintenance queries: find smallest online station in the same grid
     * 4. For offline queries: remove station from its grid's online set
     * 
     * Key insight: Union by smaller ID ensures root has smallest ID in component
     * 
     * Time: O(α(c) * q), Space: O(c)
     */
    
    vector<int> parent;
    
    int getParent(int a) {
        if (a == parent[a]) return a;
        return parent[a] = getParent(parent[a]); // Path compression
    }
    
    void unionMethod(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        // Union by smaller ID to maintain smallest root
        if (pa < pb) {
            parent[pb] = pa;
        }
        else parent[pa] = pb;
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // Initialize Union-Find
        parent.resize(c + 1);
        for (int i = 0; i <= c; ++i) parent[i] = i;
        
        // Build power grids using Union-Find
        for (auto& conn : connections) {
            unionMethod(conn[0], conn[1]);
        }
        
        // Group online stations by their grid root
        vector<set<int>> onlineStations(c + 1);
        for (int i = 1; i <= c; ++i) {
            onlineStations[getParent(i)].insert(i);
        }
        
        vector<int> result;
        
        // Process each query
        for (auto& query : queries) {
            if (query[0] == 1) { // Maintenance check
                int gridRoot = getParent(query[1]);
                
                if (onlineStations[gridRoot].empty()) {
                    result.push_back(-1); // No online stations in grid
                }
                else if (onlineStations[gridRoot].count(query[1])) {
                    result.push_back(query[1]); // Station is online
                }
                else {
                    // Return smallest online station in grid
                    result.push_back(*onlineStations[gridRoot].begin());
                }
            }
            else { // Station goes offline
                int gridRoot = getParent(query[1]);
                onlineStations[gridRoot].erase(query[1]);
            }
        }
        
        return result;
    }
};
