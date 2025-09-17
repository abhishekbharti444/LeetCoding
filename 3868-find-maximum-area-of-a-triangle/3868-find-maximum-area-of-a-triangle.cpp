    typedef long long ll;
    class Solution {
    public:
        long long maxArea(vector<vector<int>>& coords) {
            unordered_map<ll, pair<ll, ll>> x_map, y_map;
            ll max_x = INT_MIN;
            ll max_y = INT_MIN;
            ll min_x = INT_MAX;
            ll min_y = INT_MAX;

            for (int i = 0; i < coords.size(); ++i) {
                ll x = coords[i][0];
                ll y = coords[i][1];
                if (x_map.contains(x)) {
                    auto& [mny, mxy] = x_map[x];
                    mny = min(mny, y);
                    mxy = max(mxy, y);
                    x_map[x] = {mny, mxy};
                }
                else {
                    x_map[x] = {y, y};
                }

                if (y_map.contains(y)) {
                    auto& [mnx, mxx] = y_map[y];
                    mnx = min(mnx, x);
                    mxx = max(mxx, x);
                }
                else {
                    y_map[y] = {x, x};
                }

                max_x = max(max_x, x);
                max_y = max(max_y, y);
                min_x = min(min_x, x);
                min_y = min(min_y, y);
            }
            ll res = 0;
            for (auto& el: x_map) {
                auto& [mn, mx] = el.second;
                ll curr_x = el.first;
                ll curr_base = abs(mn - mx);
                ll curr_ht = max(abs(curr_x - min_x), abs(curr_x - max_x));
                res = max(res, curr_base * curr_ht);
            }
            for (auto& el: y_map) {
                auto& [mn, mx] = el.second;
                ll curr_y = el.first;
                ll curr_base = abs(mn - mx);
                ll curr_ht = max(abs(curr_y - min_y), abs(curr_y - max_y));
                res = max(res, curr_base * curr_ht);
            }
            return res == 0 ? -1 : res;
        }
    };