class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [0] * n
        for i in range(n):
            if (nums[i] == 0):
                arr[i] = -1
            else:
                arr[i] = 1
        mp = {}
        
        mp[0] = -1
        curr_sum = 0
        res = 0
        for i in range(n):
            curr_sum += arr[i]
            if curr_sum in mp:  
                res = max(res, i - mp[curr_sum])
            else:
                mp[curr_sum] = i
        return res