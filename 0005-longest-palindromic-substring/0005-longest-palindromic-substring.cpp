class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int max_len = 0;
        int start = 0;
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[i][j] = true;
                }
                else if (i + 1 == j) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    if (s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
                }

                if (dp[i][j] == true) {
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};