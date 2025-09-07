class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, int> umap;
        umap["electronics"] = 0;
        umap["grocery"] = 1;
        umap["pharmacy"] = 2;
        umap["restaurant"] = 3;
        vector<vector<string>> ans(4);
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            string curr = code[i];
            bool is_valid = true;
            for (int j = 0; j < curr.size(); ++j) {
                if (!(islower(curr[j]) || isupper(curr[j]) || isdigit(curr[j]) || curr[j] == '_')) {
                    is_valid = false;
                    break;
                }
            }
            if (curr == "") is_valid = false;
            if (!umap.contains(businessLine[i])) is_valid = false;
            if (!isActive[i]) is_valid = false;

            if (is_valid) {
                int index = umap[businessLine[i]];
                ans[index].push_back(code[i]);
            }
        }

        for (auto el: ans) {
            sort(el.begin(), el.end());
            for (auto a: el) res.push_back(a);
        }
        return res;
    }
};