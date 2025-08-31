class Solution {
public:
    /*
    SOLUTION APPROACH:
        1. Binary Search on Sorted Set: Use set to maintain sorted positions of '*' characters
        - Insert boundary markers {-1, n} to handle edge cases
        - For each new '*' at position i, use lower_bound to find nearest neighbors in O(log n)

        2. Neighbor Finding Strategy:
        - lower_bound(index) finds first '*' position ≥ index (right neighbor)
        - Decrement iterator to get left neighbor
        - This gives us the gap [start, end] where new '*' will be inserted

        3. Valid Substring Calculation:
        - When placing '*' at position i between existing '*' at positions start and end
        - New valid substrings = (i - start) × (end - i)
        - This counts all substrings that span across position i within the gap

        4. Greedy Time Simulation:
        - Process positions in order[t] sequence
        - At each step, calculate contribution of new '*' using binary search
        - Decrement k by the number of new valid substrings
        - Return first time t where k ≤ 0

        5. Set Operations:
        - lower_bound: O(log n) binary search to find insertion point
        - insert: O(log n) to maintain sorted order
        - Iterator decrement: O(1) to get left neighbor

    Time Complexity: O(n log n) - n iterations × log n set operations
    Space Complexity: O(n) - set storage for '*' positions
    */

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