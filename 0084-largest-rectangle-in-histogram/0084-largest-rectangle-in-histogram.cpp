class Solution {
public:
    struct ValIndex {
        int val;
        int index;
    };
    int largestRectangleArea(vector<int>& heights) {
        stack<ValIndex> st;
        
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!st.empty() && st.top().val > heights[i]) {
                int curr_width = i - st.top().index;
                int curr_area = st.top().val * curr_width;
                res = max(curr_area, res);
                start = st.top().index;
                st.pop();
            }
            st.push({heights[i], start});
        }
        
        
        while (!st.empty()) {
            int curr_width = n - st.top().index;
            int curr_area = st.top().val * curr_width;
            res = max(curr_area, res);
            st.pop();
        }
        return res;
    }
};