class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_time = INT_MIN;
        int prev_time = 0;
        int res = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int curr_time = logs[i][1] - prev_time;
            if (max_time <= curr_time) {
                if (max_time == curr_time) res = min(res, logs[i][0]);
                else res = logs[i][0];
                max_time = curr_time;
            }
            prev_time = logs[i][1];
        }
        return res;
    }
};