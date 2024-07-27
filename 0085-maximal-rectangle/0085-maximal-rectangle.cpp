class Solution {
public:
    
    /*
        Extension to this problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
        Inspired from this solution: https://leetcode.com/submissions/detail/1334818410/
        
        
        Approach: 
            1. The idea here is to create a heights array for each row.
                1a. The height of the current element would be one more than the last row and same col element. 
                1b. In case the current element height is 0, we can't consider any height for that element. 
            2. Pass each row as a vector to the method which solves the largest rectangle problem.
            3. Capture a potential result. 
            
            
        Time: O(M * N) as the largest rectangle can be found in O(N)
        
        Space: O(N) auxiliary space
        
        
        The solution for largest-rectangle problem approach:
        Neetcode approach: https://www.youtube.com/watch?v=zx5Sw9130L0
        
        1. Keep a monotinically increasing stack based on the val. 
        2. Whenever you encounter a smaller value than stack top:
            2a. Take out all of the elements from the stack which are smaller than curr val
            2b. Calculate a potential res with each of the stack top val. This means from the stack top index till curr val. Width would be i - stackTopIndex; height you have in stack top
            2c. The curr element should be pushed to stack with index sweeping all of the removed items from stack due to this val. For calculating this we have start index which is index of the last element that was removed from the stack because of curr value. 
        3. At last push the curr val with start index.
        4. Once the processing of heights array is done, you will have values in st in non-decreasing order. 
            4a. For each element right now, the width would be from it's index to the very last of the array. Width is hence calculated as n - stTopIndex;
            4b. Capture a potential res and keep popping from the stack. 
            
        
    */
    
    struct ValIndex {
        int val;
        int index;
    };
    
    int maximumAreaInHistogram(vector<int>& heights) {
        int n = heights.size();
        stack<ValIndex> st;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!st.empty() && st.top().val > heights[i]) {
                int curr_width = i - st.top().index;
                int curr_area = st.top().val * curr_width;
                res = max(res, curr_area);
                start = st.top().index;
                st.pop();
            }
            st.push({heights[i], start});
        }
        
        while (!st.empty()) {
            int curr_width = n - st.top().index;
            int curr_area = curr_width * st.top().val;
            res = max(res, curr_area);
            st.pop();
        }
        return res;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> prev(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (i == 0 && matrix[i][j] == '1') curr[j] = 1;
                else {
                    if (matrix[i][j] == '1') curr[j] = 1 + prev[j];
                }
                
                // cout<<curr[j]<<' ';
            }
            // cout<<"\n";
            
            int curr_max = maximumAreaInHistogram(curr);
            // cout<<curr_max<<" "<<endl;
            res = max(res, curr_max);
            
            prev = curr;
            curr.clear();
        }
        return res;
    }
};