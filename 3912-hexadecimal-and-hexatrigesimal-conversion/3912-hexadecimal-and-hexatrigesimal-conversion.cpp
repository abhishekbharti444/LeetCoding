class Solution {
public:
    string convertBase(int val, int base) {
        if (val == 0) return "0";
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";

        while (val > 0) {
            int rem = val % base;
            res = digits[rem] + res;
            val = val/base;
        }
        return res;
    }
    string concatHex36(int n) {
        string res1 = convertBase(n*n, 16);
        string res2 = convertBase(n*n*n, 36);
        return res1 + res2;
    }
};