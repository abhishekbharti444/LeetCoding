class Solution {
public:
    string formCombination(string str, int index, bool dec) {
        string new_str = str;
        if (dec) {
            if (str[index] == '0') new_str[index] = '9';
            else new_str[index] -= 1;
        }
        else {
            if (str[index] == '9') new_str[index] = '0';
            else new_str[index] += 1;
        }
        return new_str;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends_st;
        for (auto& str : deadends) ends_st.insert(str);
        
        queue<string> q;
        string start = "0000";
        q.push(start);
        int steps = 0;
        unordered_set<string> vis;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                string curr = q.front();
                q.pop();
                if (curr == target) return steps;
                if (vis.find(curr) != vis.end()) continue;
                if (ends_st.find(curr) != ends_st.end()) continue;
                vis.insert(curr);
                for (int j = 0; j < 4; ++j) {
                    string dec_str = formCombination(curr, j, true);
                    
                    string inc_str = formCombination(curr, j, false);
                    if (vis.find(dec_str) == vis.end() && ends_st.find(dec_str) == ends_st.end()) {
                        q.push(dec_str);
                    }
                    if (vis.find(inc_str) == vis.end() && ends_st.find(inc_str) == ends_st.end()) {
                        q.push(inc_str);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};