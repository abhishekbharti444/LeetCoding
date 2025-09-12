class Solution {
public:

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int a: nums) umap[a]++;
        for (auto& [key, value]: umap) {
            if (isPrime(value)) return true;
        }
        return false;
    }
};