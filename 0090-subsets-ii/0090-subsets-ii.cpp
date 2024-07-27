class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> nums;
    int n;
    set<vector<int>> st;
    void util(int index, vector<int>& comb) {
        if (index >= n) {
            if (index == n) st.insert(comb);
            return;
        }
        comb.push_back(nums[index]);
        util(index + 1, comb);
        comb.pop_back();
        util(index + 1, comb);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        this->nums = nums;
        vector<int> comb;
        util(0, comb);
        for (auto& a : st) res.push_back(a);
        return res;
    }
};