
vector<bool> isPrime(1e6, true);
class Solution {
public:
    const int upper = 1e6;
    void fillPrime() {
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < upper; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < upper; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (isPrime[0] == true) fillPrime();
        long long prime_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime[i]) prime_sum += (long long)nums[i];
        }
        long long diff = total - prime_sum;
        return abs(prime_sum - diff);
    }
};