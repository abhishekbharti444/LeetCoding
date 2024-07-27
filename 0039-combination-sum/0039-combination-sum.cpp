class Solution {
public:
    
    vector<int> cand;
    int n;
    int target;
    vector<vector<int>> res;
    void util(int index, vector<int>& comb, int curr_sum) {
        if (index == n) return;
        if (curr_sum >= target) {
            if (curr_sum == target) {
                res.push_back(comb);
            }
            return;
        }
        
        for (int i = index; i < n; ++i) {
            comb.push_back(cand[i]);
            util(i, comb, curr_sum + cand[i]);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = candidates;
        this->target = target;
        n = cand.size();
        vector<int> comb;
        util(0, comb, 0);
        return res;
    }
};