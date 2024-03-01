class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        one_count = 0
        n = len(s)
        for i in range(n):
            if s[i] == '1':
                one_count += 1;
        zero_count = n - one_count
        surplus_one = one_count - 1
        res = ""
        while surplus_one != 0:
            res += '1'
            surplus_one -= 1
        while zero_count != 0:
            res += '0'
            zero_count -= 1
        res += '1'
        return res
        
            