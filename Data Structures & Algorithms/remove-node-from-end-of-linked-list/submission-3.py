# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # using 2 pointers
        if head==None or head.next==None:
            return None
        dummy = ListNode(0, head)
        slow= dummy
        fast = dummy
        count = 0
        while 1:
            fast = fast.next
            count = count+1
            if count == n+1:
                break
        while fast:
            slow = slow.next
            fast = fast.next
        temp = slow.next.next
        slow.next.next = None
        slow.next = temp

    
        return dummy.next

        
