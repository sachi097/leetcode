# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        dummy_node = ListNode()
        l3 = dummy_node
        while l1 or l2 or carry:
            current_sum = carry
            if l1:
                current_sum += l1.val
                l1 = l1.next
            
            if l2:
                current_sum += l2.val
                l2 = l2.next
                
            carry = current_sum // 10
            current_sum = current_sum % 10

            l3.next = ListNode(current_sum)
            l3 = l3.next
        
        result_node = dummy_node.next
        del dummy_node
        return result_node
            
             