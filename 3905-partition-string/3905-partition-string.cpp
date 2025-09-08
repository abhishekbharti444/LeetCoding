class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> vis;
        string curr_str;
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            curr_str += s[i];
            if (!vis.contains(curr_str)) {
                // cout<<curr_str<<endl;
                res.push_back(curr_str);
                vis.insert(curr_str);
                curr_str = "";
            }
        }   
        return res;
    }
};