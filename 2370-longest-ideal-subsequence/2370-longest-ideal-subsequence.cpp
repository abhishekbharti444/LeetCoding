class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> memo(26, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int ch_int = s[i] - 'a';
            int curr = 1;
            for (int j = 0; j < 26; ++j) {
                if (abs(ch_int - j) <= k) curr = max(curr, 1 + memo[j]);
            }
            memo[ch_int] = curr;
        }
        return *max_element(memo.begin(), memo.end());
    }
};