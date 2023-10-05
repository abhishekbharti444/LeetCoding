class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int len = n / 3;
        unordered_map<int, int> mp;
        vector<int> res;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
            if (mp[nums[i]] > len) st.insert(nums[i]);
        }
        for (int a : st) res.push_back(a);
        return res;
    }
};