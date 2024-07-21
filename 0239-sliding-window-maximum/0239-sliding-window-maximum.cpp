class Solution {
public:
    struct data {
        int val;
        int index;
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<data> dq;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && dq.back().val <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }
        
        
        int left = 0;
        int right = k-1;
        vector<int> res;
        while (right < n) {
            while (!dq.empty() && nums[right] > dq.back().val) {
                dq.pop_back();
            }
            dq.push_back({nums[right], right});
            while (!dq.empty() && right - dq.front().index >= k) {
                dq.pop_front();
            }
            res.push_back(dq.front().val);
            right++;
        }
        // res.push_back(dq.front().val);
        return res;
    }
};