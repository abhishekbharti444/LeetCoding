class Solution {
public:
    int util(int index, vector<int>& nums, unordered_map<int, int>& mp, int n) {
        if (index >= n) return 0;
        if (mp.find(index) != mp.end()) return mp[index];
        int choose = nums[index] + util(index + 2, nums, mp, n);
        int no_choose = util(index + 1, nums, mp, n);
        return mp[index] = max(choose, no_choose);
    }
    int houseRobberOne(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        return util(0, nums, mp, n);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> vec1 = nums;
        vec1.pop_back();
        vector<int> vec2;
        for (int i = 1; i < n; ++i) vec2.push_back(nums[i]);
        return max(houseRobberOne(vec1), houseRobberOne(vec2));
    }
};