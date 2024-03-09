class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        first_index = 0
        second_index = 0
        m = len(nums1)
        n = len(nums2)
        while (first_index < m and second_index < n):
            if nums1[first_index] == nums2[second_index]:
                return nums1[first_index]
            elif nums1[first_index] < nums2[second_index]:
                first_index += 1
            else:
                second_index += 1
        
        return -1