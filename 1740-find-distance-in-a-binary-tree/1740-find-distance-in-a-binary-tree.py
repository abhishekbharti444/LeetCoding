# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Find the lca node
    # Calculate distances from the lca node for both nodes and sum them.
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:

        def util_lca(root, p, q):
            if root is None or root.val == p or root.val == q:
                return root
            left = util_lca(root.left, p, q)
            right = util_lca(root.right, p, q)
            if left is None and right is None:
                return None
            if left is None:
                return right
            if right is None:
                return left
            return root
        def find_dist(node, target):
            q = deque()
            q.append(node)
            res = 0
            while len(q) > 0:
                k = len(q)
                for i in range(k):
                    front = q.popleft()
                    if front.val == target:
                        return res
                    if front.left is not None:
                        q.append(front.left)
                    if front.right is not None:
                        q.append(front.right)
                res += 1
            return res
        lca_node = util_lca(root, p, q)
        first_dist = find_dist(lca_node, p)
        second_dist = find_dist(lca_node, q)
        return first_dist + second_dist
        