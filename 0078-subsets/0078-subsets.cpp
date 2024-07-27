class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> nums;
    void util(int index, vector<int>& comb) {
        if (index == n) {
            res.push_back(comb);
            return;
        }
        comb.push_back(nums[index]);
        util(index + 1, comb);
        comb.pop_back();
        util(index + 1, comb);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        vector<int> comb;
        util(0, comb);
        return res;
    }
};