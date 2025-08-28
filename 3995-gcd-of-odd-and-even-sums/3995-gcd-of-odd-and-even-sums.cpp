class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum_odd = 0;
        int sum_even = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            if (i % 2 == 0) sum_odd += i;
            else sum_even += i;
        }
        return gcd(sum_odd, sum_even);
    }
};