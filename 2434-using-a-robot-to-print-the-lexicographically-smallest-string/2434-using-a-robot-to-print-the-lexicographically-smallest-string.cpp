class Solution {
public:
    /*
        Took reference from this solution(Read the explanation there):
            https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/discuss/2678848/Stack-it-Up-!!-Easy-to-understand-c%2B%2B
    */
    char lowestChar(vector<int>& freq) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) return 'a' + i;
        }
        return 'a';
    }
    string robotWithString(string s) {
        stack<char> st;
        int n = s.size();
        string res = "";
        vector<int> freq(26, 0);
        for (int i = 0; i < n; ++i) freq[(s[i] - 'a')] += 1;
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            freq[(s[i]-'a')]--;
            while (!st.empty() && st.top() <= lowestChar(freq)) {
                res += st.top();
                st.pop();
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};