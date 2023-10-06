class Solution {
public:
    
    void removeFromMap(unordered_map<char, int>& mp, char ch) {
        if (mp[ch] == 1) mp.erase(ch);
        else mp[ch]--;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        if (m > n) return false;
        unordered_map<char, int> st1;
        unordered_map<char, int> st2;
        
        int left = 0;
        int right = m-1;
        
        for (int i = 0; i < m; ++i) {
            st1[s1[i]]++;
            st2[s2[i]]++;
        }
        while (right < n) {
            if (st1 == st2) return true;
            right++;
            st2[s2[right]]++;
            removeFromMap(st2, s2[left]);
            left++;
        }
        return false;
        
    }
};