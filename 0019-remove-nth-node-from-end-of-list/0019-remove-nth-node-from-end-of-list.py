# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        last = head
        res = head
        if head is None:
            return None
        while last is not None and n > 0:
            last = last.next
            n -= 1
        prev = None
        removed_node = head
        while last is not None:
            prev = removed_node
            removed_node = removed_node.next
            last = last.next
        if prev is None:
            return res.next
        if removed_node is not None:
            prev.next = removed_node.next
        return res