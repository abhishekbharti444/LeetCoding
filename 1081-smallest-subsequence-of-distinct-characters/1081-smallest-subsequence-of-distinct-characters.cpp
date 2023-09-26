class Solution {
public:
    /*
        Solved it myself after a long time.
        
Approach:
    1. Have the furthest indexes of each of chars saved in mp.
    2. Keep a monotonic stack which stores the string in lexicographical manner.
    3. Keep a set(st) also to quickly look up all of the chars present in mono_stack.
    4. In the loop 
        a. First check if the current char is already there in the 
            mono_stack(By checking it's availability in st), if true, skip to next char.
        b. Then see if curr char is smaller than top of mono_stack 
            and the top also accurs later in the string, 
            if so, pop those elements(remove from the st too).
        c. After this, add that curr char in mono_stack and st to form 
            lexicographically smallest string.
    5. At last capture mono_st in res, reverse it and return the res;
    */
    string smallestSubsequence(string s) {
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