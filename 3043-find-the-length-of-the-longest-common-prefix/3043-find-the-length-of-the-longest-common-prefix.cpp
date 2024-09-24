class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int res = 0;
        for (int a: arr1) {
            string curr = to_string(a);
            for (int i = 0; i < curr.size(); ++i) {
                string subs = curr.substr(0, i+1);
                st.insert(subs);
            }
        }
        // for (auto a: st) cout<<a<<endl;
        for (int i = 0; i < arr2.size(); ++i) {
            string curr = to_string(arr2[i]);
            for (int j = 0; j < curr.size(); ++j) {
                string subs = curr.substr(0, j+1);
                // cout<<subs<<endl;
                if (st.find(subs) != st.end()){
                    int n = subs.size();
                    res = max(res, n);
                }
            }
        }
        return res;
    }
};