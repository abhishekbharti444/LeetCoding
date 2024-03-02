class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = 0
        n = len(nums)
        res = []
        index = 0
        while index < n: 
            if (nums[index] >= 0):
                break
            index += 1
        left = index - 1
        right = index
        while (left >= 0 and right < n): 
            if (abs(nums[left]) < abs(nums[right])):
                res.append(pow(nums[left], 2))
                left -= 1
            else:
                res.append(pow(nums[right], 2))
                right += 1
        while (left >= 0):
            res.append(pow(nums[left], 2))
            left -= 1
        while (right < n):
            res.append(pow(nums[right], 2))
            right += 1
        return res