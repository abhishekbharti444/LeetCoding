class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp_s, mp_t;
        for (char ch : s) mp_s[ch]++;
        for (char ch : t) mp_t[ch]++;
        return mp_s == mp_t;
    }
};