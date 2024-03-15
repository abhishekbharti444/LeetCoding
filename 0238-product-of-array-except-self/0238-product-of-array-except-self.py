class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        count_zeroes = 0
        res = [0] * n
        prod_val = 1
        for i in range(n):
            if nums[i] == 0:
                count_zeroes += 1
                if (count_zeroes > 1):
                    break
                if (count_zeroes == 1):
                    continue
            prod_val *= nums[i]
                
        if (count_zeroes > 1):
            return [0] * n
    
        for i in range(n):
            if (nums[i] == 0):
                res[i] = prod_val
                continue
            if (count_zeroes > 0):
                res[i] = 0
                continue
            res[i] = prod_val // nums[i]
    
        return res