# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def util(root, p, q): 
            if root is None:
                return root
            if root == p or root == q:
                return root
            left = util(root.left, p, q)
            right = util(root.right, p, q)
            if left is None and right is None: 
                return None
            if left is None:
                return right
            if right is None: 
                return left
            return root
        return util(root, p, q)