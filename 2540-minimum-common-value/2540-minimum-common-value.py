class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        st = set()
        for i in range(len(nums1)):
            st.add(nums1[i])
        for i in range(len(nums2)):
            if nums2[i] in st:
                return nums2[i]
        
        return -1