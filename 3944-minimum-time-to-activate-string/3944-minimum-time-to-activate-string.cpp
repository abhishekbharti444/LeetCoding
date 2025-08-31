class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        set<int> st;
        st.insert(-1);
        st.insert(n);

        for (int i = 0; i < n; ++i) {
            int index = order[i];
            // Find nearest neighbors
            auto it = st.lower_bound(index);
            int end = *it;
            --it;
            int start = *it;
            long long count = (long long)(index - start) * (end - index);
            k -= count;
            st.insert(index); // Include this in the set marking this as *
            if (k <= 0) return i;
        }
        return -1;
    }
};