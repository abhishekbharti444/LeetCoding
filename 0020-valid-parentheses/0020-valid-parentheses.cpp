class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if (s[i] == ')') {
                    if (st.empty() || st.top() != '(') return false;
                }
                else if (s[i] == '}') {
                    if (st.empty() || st.top() != '{') return false;
                }
                else if (s[i] == ']') {
                    if (st.empty() || st.top() != '[') return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};