class Solution {
public:
    char processStr(string s, long long k) {
        long long final_len = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '%') continue;
            else if (s[i] == '#') final_len += final_len;
            else if (s[i] == '*' && final_len > 0) final_len -= 1;
            else if (islower(s[i])) final_len += 1;
        }
        if (final_len <= k) return '.';

        long long curr_len = final_len;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '%') k = curr_len - 1 - k;
            else if (islower(s[i])) {
                if (k == curr_len - 1) return s[i];
                curr_len--;
            } 
            else if (s[i] == '*') curr_len += 1;
            else if (s[i] == '#') {
                curr_len /= 2;
                if (k >= curr_len) {
                    k = k - curr_len;
                }
            }
        }
        return '.';
    }
};