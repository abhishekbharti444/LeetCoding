class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        unordered_map<string, vector<int>> mp;
        
        for (int i = 0; i < m; ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> res;
        for (auto a : mp) {
            vector<string> temp;
            for (int i = 0; i < a.second.size(); ++i) {
                temp.push_back(strs[a.second[i]]);
            }
            res.push_back(temp);
        }
        return res;
        
    }
};