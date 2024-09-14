class Solution {
public:
    
    long long sumOfDigits(long long n) {
        long long res = 0;
        while (n > 0) {
            res += (n%10);
            n /= 10;
        }
        return res;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long base = 1;
        long long curr = n;
        
        while (sumOfDigits(curr) > target) {
            curr = (curr / 10) + 1;
            base *= 10;
        }
        return curr * base - n;
    }
};