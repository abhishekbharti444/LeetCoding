# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = deque()
        q.append(root)
        level = 1
        def check(arr, inc):
            n = len(arr)
            if inc == 0: 
                for i in range(n):
                    if arr[i] % 2 == 0: 
                        return False
                    if i == n-1:
                        return True 
                    if arr[i] >= arr[i+1]:
                        return False
            if inc == 1: 
                for i in range(n): 
                    if arr[i] % 2 != 0:
                        return False
                    if i == n-1:
                        return True
                    if arr[i] <= arr[i+1]:
                        return False
            return true
        while len(q) > 0:
            arr = []
            for i in range(len(q)):
                front = q.popleft()
                arr.append(front.val)
                if front.left is not None:
                    q.append(front.left)
                if front.right is not None:
                    q.append(front.right)
            # for i in range(len(arr)):
            #     print(arr[i])
            if level % 2 == 0 and check(arr, 1) == False:
                return False
            elif level % 2 == 1 and check(arr, 0) == False: 
                return False
            level += 1
            
        return True