class Solution {
public:
    
    
        /*
    A general approach to backtracking questions (Subsets, Permutations, Combination Sum, Palindrome Partioning)
    
    Read this article : 
    https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
    */
    vector<vector<int>> res;
    int n;
    vector<int> nums;
    void util(int index, vector<int>& comb) {
        if (index > n) return;
        if (index == n) {
            res.push_back(comb);
            return;
        }
        for (int i = index; i < n; ++i) {
            swap(comb[i], comb[index]);
            util(index + 1, comb);
            swap(comb[i], comb[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> comb;
        this->nums = nums;
        n = nums.size();
        comb = nums;
        
        util(0, comb);
        return res;
    }
};