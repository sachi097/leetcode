/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    void reverseList(ListNode head){
        if(head == null || head.next == null){
            return;
        }
        reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return;
    }

    ListNode getKthNode(ListNode temp, int k){
        k -= 1;
        while (temp != null && k > 0) {
            k--;
            temp = temp.next;
        }
        return temp;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode prevLast = null, nextNode, tempNode = head;

        while(tempNode != null){
            ListNode kthNode = getKthNode(tempNode, k);
            
            if(kthNode == null){
                if (prevLast != null) {
                    prevLast.next = tempNode;
                }
                break;
            }

            nextNode = kthNode.next;
            kthNode.next = null;

            reverseList(tempNode);
            if(tempNode == head){
                head = kthNode;
            }
            else{
                prevLast.next = kthNode;
            }

            prevLast = tempNode;
            tempNode = nextNode;
        }

        return head;
    }
}