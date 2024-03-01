class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        one_count = s.count('1')
        zero_count = len(s) - one_count
        return '1' * (one_count - 1) + '0' * zero_count + '1'
        
            