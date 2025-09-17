
const int max_val = 1e5 + 7;
vector<bool> isPrime(max_val, true);
class Solution {
public:
    void fillPrime() {
        if (isPrime[0] == false) return;
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < isPrime.size(); ++i) {
            if (isPrime[i] == false) continue;
            for (int j = i * i; j < isPrime.size(); j += i) {
                isPrime[j] = false;
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        fillPrime();
        int left = 0; 
        int right = 0;
        multiset<int> mulset;
        int n = nums.size();
        int res = 0;
        int prev = -1;
        int curr = -1;
        while (right < n) {
            if (isPrime[nums[right]]) {
                prev = curr;
                curr = right;
                mulset.insert(nums[right]);
            }
            while (left < n && mulset.size() > 0 && *mulset.rbegin() - *mulset.begin() > k) {
                if (isPrime[nums[left]]) mulset.erase(mulset.find(nums[left]));
                left++;
            }

            if (mulset.size() >= 2) {
                res += prev - left + 1;
            }
            right++;
        }
        return res;
    }
};