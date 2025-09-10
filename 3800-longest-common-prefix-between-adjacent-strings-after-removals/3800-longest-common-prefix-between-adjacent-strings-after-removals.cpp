class Solution {
public:
    int similarity(string a, string b) {
        int index = 0;
        int m = a.size();
        int n = b.size();
        while (index < m && index < n) {
            if (a[index] != b[index]) return index;
            index++;
        }
        return index;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        int curr_max = 0;
        for (int i = 1; i < n; ++i) {
            int sim = similarity(words[i], words[i-1]);
            curr_max = max(sim, curr_max);
            pre[i] = curr_max;
        }
        curr_max = 0;
        for (int i = n-2; i >= 0; --i) {
            int sim = similarity(words[i], words[i+1]);
            curr_max = max(sim, curr_max);
            suf[i] = curr_max;
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (i + 1 < n) res[i] = suf[i+1];
            }
            else if (i == n-1) {
                if (i - 1 >= 0) res[i] = pre[i-1];
            }
            else {
                res[i] = max(similarity(words[i-1], words[i+1]), max(suf[i+1], pre[i-1]));
            }
        }
        return res;
    }
};