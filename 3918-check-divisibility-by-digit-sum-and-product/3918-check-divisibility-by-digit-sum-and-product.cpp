class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int a = n;
        while (a > 0) {
            int rem = a % 10;
            sum += rem;
            prod *= rem;
            a /= 10;
        }
        return (sum + prod) % n == 0;
    }
};