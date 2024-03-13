class Solution:
    def pivotInteger(self, n: int) -> int:
        pre_sum = 0
        total = n * (n + 1)/2
        for i in range(1, n+1):
            pre_sum += i
            if total - pre_sum + i == pre_sum:
                return i
        return -1
            