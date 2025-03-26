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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2)
    {
        if(list1 == null)
            return list2;
        
        if(list2 == null)
            return list1;
        
        if(list1.val <= list2.val){
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        }
        else{
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }

    private ListNode mergeKListsHelper(ListNode[] lists, int left, int right)
    {
        if (left == right) 
        {
            return lists[left];
        }
        
        if(left > right){
            return null;
        }

        int mid = left + (right - left) / 2;

        ListNode l1 = mergeKListsHelper(lists, left, mid);
        ListNode l2 = mergeKListsHelper(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    public ListNode mergeKLists(ListNode[] lists)
    {
        if (lists.length == 0) 
        {
            return null;
        }

        return mergeKListsHelper(lists, 0, lists.length - 1);
    }
}