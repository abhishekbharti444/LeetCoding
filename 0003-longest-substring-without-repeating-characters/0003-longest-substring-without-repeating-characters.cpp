class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_set<char> st;
        int res = 0;
        while (right < n) {
            if (st.find(s[right]) != st.end()) {
                while (left < right && st.find(s[right]) != st.end()) {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};