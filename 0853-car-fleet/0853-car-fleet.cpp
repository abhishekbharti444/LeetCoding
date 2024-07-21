class Solution {
public:
    struct data {
        int pos;
        int sp;
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n);
        vector<data> info;
        for (int i = 0; i < n; ++i) info.push_back({position[i], speed[i]});
        auto lmd = [&](auto& a, auto& b) {
            return a.pos < b.pos;
        };
        sort(info.begin(), info.end(), lmd);
        
        for (int i = 0; i < n; ++i) {
            time[i] = (double)(target - info[i].pos)/info[i].sp;
        }
        int res = 0;
        double curr_max = -DBL_MAX;
        for (int i = n-1; i >= 0; --i) {
            cout<<time[i]<<" ";
            if (curr_max < time[i]) {
                curr_max = time[i];
                res++;
            }
        }
        return res;
    }
};