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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    TreeNode buildBST(ListNode head){
        if(head == null){
            return null;
        }
        
        if(head.next == null){
            return new TreeNode(head.val);
        }

        ListNode slow = head, fast = head, slowPrev = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slowPrev = slow;
            slow = slow.next;
        }
        
        TreeNode root = new TreeNode(slow.val);
        slowPrev.next = null;
        root.left = buildBST(head);
        root.right = buildBST(slow.next);

        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        return buildBST(head);
    }
}