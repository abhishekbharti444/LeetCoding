class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr1[i]]++;
        }
        
        int m = arr2.size();
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            if (mp.find(arr2[i]) == mp.end()) continue;
            int count = mp[arr2[i]];
            for (int j = 0; j < count; ++j) res.push_back(arr2[i]);
            mp.erase(arr2[i]);
        }
        
        for (auto a : mp) {
            for (int i = 0; i < a.second; ++i) {
                res.push_back(a.first);
            }
        }
        return res;
    }
};