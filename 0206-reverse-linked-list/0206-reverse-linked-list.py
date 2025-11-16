# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # if head == None:
        #     return head

        # prev_ptr = None
        # while(head):
        #     temp = head.next
        #     head.next = prev_ptr
        #     prev_ptr = head
        #     head = temp

        # return prev_ptr

        if head == None:
            return head

        if head.next == None:
            return head
        
        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None

        return new_head







