class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        char res;
        for (char ch : t) {
            if (mp.find(ch) == mp.end()) return ch;
            if (mp[ch] == 0) return ch;
            mp[ch]--;
        }
        return res;
    }
};