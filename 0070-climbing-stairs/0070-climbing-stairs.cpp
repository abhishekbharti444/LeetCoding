class Solution {
public:
    unordered_map<int, int> mp;
    int util(int index) {
        if (index == 0 || index == 1) return 1;
        if (mp.find(index) != mp.end()) return mp[index];
        return mp[index] = util(index - 1) + util(index - 2);
    }
    int climbStairs(int n) {
        return util(n);
    }
};