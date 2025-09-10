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
        if (n <= 1) return vector<int>(n, 0);
        
        // Store individual pair similarities
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        
        for (int i = 1; i < n; ++i) {
            int sim = similarity(words[i-1], words[i]);
            pre[i] = max(sim, pre[i-1]);
        }
        for (int i = n-2; i >= 0; --i) {
            int sim = similarity(words[i+1], words[i]);
            suf[i] = max(sim, suf[i+1]);
        }
        
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int best = 0;
            // Left pairs: use prefmax[i-2] 
            if (i >= 2) best = max(best, pre[i-1]);
            // Right pairs: use sufmax[i+1]
            if (i <= n-3) best = max(best, suf[i+1]);
            // Bridge pair: words[i-1] and words[i+1]
            if (i > 0 && i < n-1) {
                best = max(best, similarity(words[i-1], words[i+1]));
            }
            res[i] = best;
        }
        return res;
    }
};
