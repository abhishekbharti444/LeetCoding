class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int edge_len = roads.size();
        
        vector<pair<int, int>> vec;
        unordered_map<int, int> mp;
        for (int i = 0; i < edge_len; ++i) {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (mp.find(i) == mp.end()) mp[i] = 0;
        }
        for (auto& el: mp) {
            vec.push_back(el);
        }
        auto lmd = [&](auto& a, auto& b) {
            return a.second < b.second;
        };
        sort(vec.begin(), vec.end(), lmd);
        int k = 1;
        for (int i = 0; i < vec.size(); ++i) {
            mp[vec[i].first] = i;
            // cout<<vec[i].first<<" "<<vec[i].second<<endl;
            vec[i].second = k;
            k++;
        }
        
        
        long long res = 0;
        for (int i = 0; i < edge_len; ++i) {
            int vec_index1 = mp[roads[i][0]];
            int vec_index2 = mp[roads[i][1]];
            res += vec[vec_index1].second + vec[vec_index2].second;
        }
        return res;
    }
};