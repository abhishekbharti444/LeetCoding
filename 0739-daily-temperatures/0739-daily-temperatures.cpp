class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> res;
        for (int i = n - 1; i >= 0; --i) {
            if (st.empty()) {
                st.push(i);
                res.push_back(0);
            }
            else {
                while (!st.empty() && temp[i] >= temp[st.top()]) {
                    st.pop();
                }
                if (st.empty()) {
                    res.push_back(0);
                }
                else {
                    res.push_back(st.top() - i);
                }
                st.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};