class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int start = newInterval[0];
        int end = newInterval[1];
        int index = 0;
        while (index < n && start > intervals[index][1]) {
            res.push_back(intervals[index]);
            index++;
        }
        while (index < n && end >= intervals[index][0]) {
            start = min(start, intervals[index][0]);
            end = max(end, intervals[index][1]);
            index++;
        }
        
        res.push_back({start, end});
        
        while (index < n) {
            res.push_back(intervals[index]);
            index++;
        }
        
        return res;
    }
};