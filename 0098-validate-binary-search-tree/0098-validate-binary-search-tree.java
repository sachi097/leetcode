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
    public static boolean isBST(TreeNode root, Long minValue, Long maxValue){
        if(root == null){
            return true;
        }
        if(minValue < root.val && root.val < maxValue){
            return isBST(root.left, minValue, (long) root.val) && isBST(root.right, (long) root.val, maxValue);
        }
        return false;
    }

    public boolean isValidBST(TreeNode root) {
        return isBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}