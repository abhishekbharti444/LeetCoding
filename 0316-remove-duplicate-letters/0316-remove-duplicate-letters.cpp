class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> mono_st;
        unordered_map<char, int> mp;
        unordered_set<char> st;
        
        for (int i = 0; i < n; ++i) mp[s[i]] = i;
        
        for (int i = 0; i < n; ++i) {
            if (st.find(s[i]) != st.end()) continue;
            while (!mono_st.empty() && s[i] < mono_st.top() && mp[mono_st.top()] > i) {
                char ch = mono_st.top();
                st.erase(ch);
                mono_st.pop();
            }
            mono_st.push(s[i]);
            st.insert(s[i]);
        }
        
        string res;
        while (!mono_st.empty()) {
            res.push_back(mono_st.top());
            mono_st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};