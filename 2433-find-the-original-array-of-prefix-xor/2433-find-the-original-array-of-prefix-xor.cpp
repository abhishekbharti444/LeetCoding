class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) res[i] = pref[i];
            else {
                res[i] = pref[i-1] ^ pref[i];
            }
        }
        return res;
    }
};