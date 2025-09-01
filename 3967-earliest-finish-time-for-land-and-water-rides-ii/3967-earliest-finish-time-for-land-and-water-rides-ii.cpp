class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int min_l = INT_MAX;        // Minimum land ride finish time
        int min_w = INT_MAX;        // Minimum water ride finish time
        int land_water = INT_MAX;   // Best time for land→water strategy
        int water_land = INT_MAX;   // Best time for water→land strategy
        
        // Find fastest land ride completion time
        for (int i = 0; i < ls.size(); ++i) {
            min_l = min(min_l, ls[i] + ld[i]);
        }
        
        // Strategy 1: Land first, then water
        // For each water ride, calculate total time if land ride finishes at min_l
        for (int i = 0; i < ws.size(); ++i) {
            min_w = min(min_w, ws[i] + wd[i]);
            // Water ride starts at max(land_finish_time, water_start_time)
            // Total time = water_duration + max(min_l, water_start_time)
            land_water = min(land_water, wd[i] + max(min_l, ws[i]));
        }

        // Strategy 2: Water first, then land  
        // For each land ride, calculate total time if water ride finishes at min_w
        for (int i = 0; i < ls.size(); ++i) {
            // Land ride starts at max(water_finish_time, land_start_time)
            // Total time = land_duration + max(min_w, land_start_time)
            water_land = min(water_land, ld[i] + max(min_w, ls[i]));
        }
        
        // Return best strategy
        return min(land_water, water_land);
    }
};