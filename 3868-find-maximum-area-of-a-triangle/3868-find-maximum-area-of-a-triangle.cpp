typedef long long ll;
class Solution {
public:
    /*
    Approach Summary:
    1. Group points by x-coordinates (vertical lines) and y-coordinates (horizontal lines)
    2. For each line with multiple points, calculate the maximum base (distance between farthest points on that line)
    3. For each such line, calculate maximum possible height (distance to the farthest point in the perpendicular direction)
    4. Triangle area = base * height, return maximum area found
    Key insight: To maximize area, use the longest possible base on a line and the farthest perpendicular point
    */
    
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<ll, pair<ll, ll>> x_map, y_map; // Maps coordinate -> {min, max} on that line
        ll max_x = INT_MIN, max_y = INT_MIN, min_x = INT_MAX, min_y = INT_MAX;

        // Group points and track global bounds
        for (int i = 0; i < coords.size(); ++i) {
            ll x = coords[i][0], y = coords[i][1];
            
            // Track min/max y-values for each x-coordinate (vertical lines)
            if (x_map.contains(x)) {
                auto& [mny, mxy] = x_map[x];
                mny = min(mny, y);
                mxy = max(mxy, y);
                x_map[x] = {mny, mxy};
            }
            else {
                x_map[x] = {y, y};
            }

            // Track min/max x-values for each y-coordinate (horizontal lines)
            if (y_map.contains(y)) {
                auto& [mnx, mxx] = y_map[y];
                mnx = min(mnx, x);
                mxx = max(mxx, x);
            }
            else {
                y_map[y] = {x, x};
            }

            // Track global bounds for height calculations
            max_x = max(max_x, x);
            max_y = max(max_y, y);
            min_x = min(min_x, x);
            min_y = min(min_y, y);
        }
        
        ll res = 0;
        
        // Try vertical lines as base
        for (auto& el: x_map) {
            auto& [mn, mx] = el.second;
            ll curr_x = el.first;
            ll curr_base = abs(mn - mx);                              // Base length on this vertical line
            ll curr_ht = max(abs(curr_x - min_x), abs(curr_x - max_x)); // Max perpendicular distance
            res = max(res, curr_base * curr_ht);                      // Area = base * height
        }
        
        // Try horizontal lines as base
        for (auto& el: y_map) {
            auto& [mn, mx] = el.second;
            ll curr_y = el.first;
            ll curr_base = abs(mn - mx);                              // Base length on this horizontal line
            ll curr_ht = max(abs(curr_y - min_y), abs(curr_y - max_y)); // Max perpendicular distance
            res = max(res, curr_base * curr_ht);                      // Area = base * height
        }
        
        return res == 0 ? -1 : res;
    }
};
