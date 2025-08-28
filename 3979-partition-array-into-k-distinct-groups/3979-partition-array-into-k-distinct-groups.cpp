class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        int max_freq = 0;
        int group_size = n/k;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) mp[nums[i]]++;
        int distinct = mp.size();
        for (auto el: mp) {
            max_freq = max(max_freq, el.second);
        }
        if (max_freq > group_size) return false;
        if (distinct < k) return false;
        return true;

    }
};