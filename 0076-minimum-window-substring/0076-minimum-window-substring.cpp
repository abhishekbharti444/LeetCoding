class Solution {
public:
    bool sContainsT(unordered_map<char, int>& s_mp, unordered_map<char, int>& t_mp) {
        for (auto& a : t_mp) {
            if (s_mp.find(a.first) == s_mp.end()) return false;
            if (s_mp[a.first] < a.second) return false;
        }
        return true;
    }
    void eraseFromMap(unordered_map<char, int>& s_mp, char key) {
        if (s_mp[key] > 1) s_mp[key]--;
        else s_mp.erase(key);
    } 
    string minWindow(string s, string t) {
        int m = s.size(); 
        int n = t.size();
        unordered_map<char, int> s_mp, t_mp;
        
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < n; ++i) {
            t_mp[t[i]]++;
        }
        int res = INT_MAX;
        int index = -1;
        while (right < m) {
            s_mp[s[right]]++;
            while (left <= right && sContainsT(s_mp, t_mp)) {

                if (res > right - left + 1) {
                    index = left;
                    res = right - left + 1;
                }              
                eraseFromMap(s_mp, s[left]);
                left++;
            }
            right++;
        }
        return res == INT_MAX ? "" : s.substr(index, res);
    }
};