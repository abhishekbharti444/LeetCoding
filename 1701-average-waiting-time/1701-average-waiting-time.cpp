class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int curr_time = customers[0][0];
        double wait_time = 0;
        
        for (int i = 0; i < n; ++i) {
            if (curr_time < customers[i][0]) {
                curr_time = customers[i][0];
            }
            int curr_final_time = curr_time + customers[i][1];
            curr_time = curr_final_time;
            int curr_wait_time = curr_final_time - customers[i][0];
            // cout<<curr_wait_time<<" ";
            // if (i == 0) continue;
            wait_time += curr_wait_time/(double)n;
            // wait_time += curr_wait_time;
        }
        
        return wait_time;
    }
};