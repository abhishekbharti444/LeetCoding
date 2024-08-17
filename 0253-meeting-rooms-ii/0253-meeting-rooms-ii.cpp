class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        
        for (int i = 0; i < intervals.size(); ++i) {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }
        int res = 0;
        int curr = 0;
        for (auto& a : mp) {
            curr += a.second;
            res = max(res, curr);
        }
        return res;
    }
};