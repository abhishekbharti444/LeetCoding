class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: 
            return -1
        slow = nums[0]
        fast = nums[nums[0]]
        
        while (slow != fast):
            slow = nums[slow]
            fast = nums[nums[fast]]
            
        fast = 0
        while (slow != fast):
            slow = nums[slow]
            fast = nums[fast]
            
        return fast