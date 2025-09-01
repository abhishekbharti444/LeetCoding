class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int min_l = INT_MAX;
        int min_w = INT_MAX;
        int land_water = INT_MAX;
        int water_land = INT_MAX;
        for (int i = 0; i < ls.size(); ++i) {
            min_l = min(min_l, ls[i] + ld[i]);
        }
        for (int i = 0; i < ws.size(); ++i) {
            min_w = min(min_w, ws[i] + wd[i]);
            land_water = min(land_water, wd[i] + max(min_l, ws[i]));
        }

        for (int i = 0; i < ls.size(); ++i) {
            water_land = min(water_land, ld[i] + max(min_w, ls[i]));
        }
        return min(land_water, water_land);
    }
};