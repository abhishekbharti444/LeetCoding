class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> res;
    
    void util(int index, vector<int>& comb) {
        // if (index == n) {
        //     res.push_back(comb);
        //     return;
        // }
        res.push_back(comb);
        for (int i = index; i < n; ++i) {
            if (i > index && nums[i] == nums[i-1]) continue;
            comb.push_back(nums[i]);
            util(i+1, comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        n = nums.size();
        vector<int> comb;
        util(0, comb);
        return res;
    }
};