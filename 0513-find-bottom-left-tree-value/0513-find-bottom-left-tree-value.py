# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append(root)
        res = root.val;
        while len(q) > 0: 
            k = len(q)
            index = 0;
            for i in range(k):
                front = q.popleft()
                if front is not None:
                    if index == 0:
                        res = front.val;
                if front.left is not None:
                    q.append(front.left)
                if front.right is not None: 
                    q.append(front.right)
                index += 1
        return res