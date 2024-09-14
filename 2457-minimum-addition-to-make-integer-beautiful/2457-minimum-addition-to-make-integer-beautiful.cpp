class Solution {
public:
    
    
    /*
        Solution inspired by lee215: https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/discuss/2758216/JavaC%2B%2BPython-Straight-Forward-Solution
        
        Approah: 
            1. Write a function which can return the sum of digits
            2. Have a value base which you can multiply later with the remaining of n
            3. Finally return the value after multiplying with base and then subtracting with the original n;
            
        Time: O(logN * logN)
    */
    
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