class Solution {
public:
    int total_hours;
    bool util(vector<int>& piles, int val) {
        int n = piles.size();
        int count_hours = 0;
        for (int i = 0; i < n; ++i) {
            if (count_hours > total_hours) return false;
            count_hours += piles[i]/val;
            if (piles[i] % val != 0) count_hours++;
        }
        return count_hours <= total_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        total_hours = h;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (util(piles, mid)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};