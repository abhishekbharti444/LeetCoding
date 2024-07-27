class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> cand;
    int n;
    int target;
    
    void util(int curr, vector<int>& comb, int curr_sum) {
        if (curr_sum >= target) {
            if (curr_sum == target) res.push_back(comb);
            return;
        }
        
        for (int i = curr; i < n; ++i) {
            
            // It is to prevent duplication
            // i > cur: before explaining this, first recall what cur is? cur points to the index which we start with in the first place before entering the for loop. It is the starting value from which we started picking up numbers. Since it's the starting point, so we will definitely take this number. i indicates the index which we are currently processing. Mind that in one recursive call stack the value of cur is not going to change but the value of i will keep on changing. If this is clear, then i > cur is simple to understand, it means that we are currently considering a position which is greater then cur.

            // Now, consider the second condition cand[i] == cand[i - 1], we are considering an index which is greater than curr because that must be true if we are checking this condition, meaning we have already taken the number which is at cur, so if the number after curr has the same value, then we won't consider it again because that will be duplication. And that explains the condition.
            
            if (i != curr && cand[i] == cand[i-1]) continue;
            
            comb.push_back(cand[i]);
            util(i + 1, comb, curr_sum + cand[i]);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        cand = candidates;
        sort(cand.begin(), cand.end());
        n = cand.size();
        vector<int> comb;
        util(0, comb, 0);
        return res;
    }
};