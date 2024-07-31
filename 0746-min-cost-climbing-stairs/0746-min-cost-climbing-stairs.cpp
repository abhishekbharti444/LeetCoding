class Solution {
public:
    vector<int> c;
    int n;
    unordered_map<int, int> mp;
    int util(int index) {
        if (index >= n) return 0;
        if (index >= n-2) return c[index];
        if (mp.find(index) != mp.end()) return mp[index];

        return mp[index] = c[index] + min(util(index + 1), util(index + 2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        c = cost;
        n = c.size();
        
        return min(util(0), util(1));
    }
};