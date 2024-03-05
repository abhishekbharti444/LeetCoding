class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        left = 0
        right = n-1
        while (left <= right):
            ch_left = s[left]
            ch_right = s[right]
            if (left == right):
                break
            if (ch_left != ch_right):
                return right - left + 1
            while (left <= right and s[left] == ch_left):
                left += 1
            while (left <= right and s[right] == ch_right):
                right -= 1
        # print(left, s[left], right, s[right])
        return right - left + 1 if left <= right else 0