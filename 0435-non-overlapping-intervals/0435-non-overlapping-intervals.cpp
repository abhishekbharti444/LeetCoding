class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;
        int index = 1;
        int res = 0;
        auto lmd = [&](auto& a, auto& b) {
            if (a[1]==b[1]) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), lmd);
        while (index <= n && i < n) {
            while (index < n && intervals[index][0] < intervals[i][1]) {
                index++;
                res++;
            }
            i = index;
            index++;
        }
        return res;
        
    }
};