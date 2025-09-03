/*
SOLUTION APPROACH: Prime-Based Array Splitting

PROBLEM: Split array into two parts to minimize absolute difference between sums
- One part: elements at prime indices
- Other part: remaining elements

ALGORITHM:
1. Precompute all primes up to array size using Sieve of Eratosthenes
2. Calculate total sum of array (avoiding overflow)
3. Sum elements at prime indices
4. Other sum = total - prime_sum
5. Return absolute difference

KEY OPTIMIZATIONS:
- Global prime array with lazy initialization (avoids TLE)
- Use long long for accumulation to prevent integer overflow
- Sieve precomputation is O(n log log n), much faster than checking each index

EDGE CASES:
- Empty array or single element
- All indices prime vs no indices prime
- Large sums requiring long long arithmetic
*/

vector<bool> isPrime(1e6 + 1, true);  // Global array, size 1e6+1 for safety

class Solution {
public:
    void fillPrime() {
        isPrime[0] = isPrime[1] = false;
        
        // Sieve of Eratosthenes: mark all composite numbers
        for (int i = 2; i * i <= 1e6; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i as composite
                for (int j = i * i; j <= 1e6; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    long long splitArray(vector<int>& nums) {
        // Lazy initialization: compute primes only once across all test cases
        if (isPrime[0] == true) fillPrime();
        
        // Calculate total sum using long long to avoid overflow
        // CRITICAL: Use 0LL to ensure accumulate works in long long arithmetic
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        
        // Sum elements at prime indices
        long long prime_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime[i]) {
                prime_sum += nums[i];
            }
        }
        
        // Calculate sum of non-prime indices
        long long non_prime_sum = total - prime_sum;
        
        // Return absolute difference between the two parts
        return abs(prime_sum - non_prime_sum);
    }
};
