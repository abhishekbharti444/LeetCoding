class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int m = c.size();
        
        long long total_time = 0;
        int curr = c[0][0];
        for (int i = 0; i < m; ++i) {
            curr = max(curr, c[i][0]);
            curr += c[i][1];
            
            total_time += curr - c[i][0];
            cout<<curr<<" ";
        }
        return (double)total_time/m;
    }
};