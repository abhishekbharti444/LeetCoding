class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int res = -1;
        for (int a : nums) st.insert(a);
        for (int a : nums) {
            if (a < 0) continue;
            else {
                if (st.find(-a) != st.end()) res = max(res, a);
            }
        }
        return res;
    }
};