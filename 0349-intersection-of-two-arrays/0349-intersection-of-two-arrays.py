class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m = len(nums1)
        n = len(nums2)
        st = set()
        res_st = set()
        for a in nums1:
            st.add(a)
        for a in nums2:
            if a in st:
                res_st.add(a)
        return list(res_st)
                