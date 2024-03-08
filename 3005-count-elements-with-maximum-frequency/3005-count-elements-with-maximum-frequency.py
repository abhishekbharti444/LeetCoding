class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        dict = defaultdict(int)
        n = len(nums)
        max_freq = 0
        for i in range(n):
            dict[nums[i]] += 1
            max_freq = max(max_freq, dict[nums[i]])

        res = 0
        for val in dict.values():
            if val == max_freq:
                res += 1
        return res * max_freq
        