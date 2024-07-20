class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        int n = nums.size();
        for (int a : nums) st.insert(a);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (st.find(nums[i] + 1) != st.end()) continue;
            int count = 0;
            int curr = nums[i];
            while (st.find(curr) != st.end()) {
                curr -= 1;
                count++;
            }
            res = max(res, count);
        } 
        return res;
    }
};