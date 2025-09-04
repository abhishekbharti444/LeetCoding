class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (res.size() > 0) {
                    res.pop_back();
                }
            }
            else if (s[i] == '#') {
                string temp = res;
                res += temp;
            }
            else if (s[i] == '%') {
                reverse(res.begin(), res.end());
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};