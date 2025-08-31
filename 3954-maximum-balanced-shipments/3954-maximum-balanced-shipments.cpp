class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int res = 0;
        int curr_len = 0;
        int curr_max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            curr_len++;
            curr_max = max(curr_max, weight[i]);
            if (curr_len < 2) continue;
            if (weight[i] < curr_max) {
                res++;
                curr_len = 0;
                curr_max = INT_MIN;
            }
        }
        return res;
    }
};