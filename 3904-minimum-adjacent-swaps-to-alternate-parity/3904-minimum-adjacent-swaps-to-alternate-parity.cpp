class Solution {
public:
    int util(vector<int>& vec) {
        int len = vec.size();
        int res = 0;
        for (int i = 0; i < len; ++i) {
            // When you are starting from 0, the target where this index would be 
            // in the main array would be 2 * i
            res += abs(vec[i] - 2 * i);
        }
        return res;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd_index, even_index;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) even_index.push_back(i);
            else odd_index.push_back(i);
        }
        int odd_count = odd_index.size();
        int even_count = even_index.size();
        if (abs(odd_count - even_count) > 1) return -1;
        
        int res = INT_MAX;
        if (even_count > odd_count) {
            res = min(res, util(even_index));
        }
        else if (even_count < odd_count) res = min(res, util(odd_index));
        else res = min(res, min(util(even_index), util(odd_index)));
        return res;
    }
};