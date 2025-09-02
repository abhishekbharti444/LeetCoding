class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        if (s[0] == 'L') pre[0] = 1;
        if (s[n-1] == 'T') suf[n-1] = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == 'L') pre[i] = 1 + pre[i-1];
            else pre[i] = pre[i-1];
        }
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == 'T') suf[i] = 1 + suf[i+1];
            else suf[i] = suf[i+1];
        }
        long long op1 = 0;
        long long op2 = 0;
        long long op3 = 0;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'C') {
                op1 += (pre[i] + 1) * suf[i]; // Add L at the beginning
                op2 += pre[i] * (suf[i] + 1); // Add T at the end
                op3 += pre[i] * suf[i]; 
            }
            else {
                res = max(res, (long long)pre[i] * suf[i]);
            }
        }
        return max({op1, op2, op3 + res});
    }
};