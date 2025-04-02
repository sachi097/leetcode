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
    int findMaxPath(TreeNode root, int[] maxPath){
        if(root == null){
            return 0;
        }

        int leftPathSum = Math.max(0, findMaxPath(root.left, maxPath));
        int rightPathSum = Math.max(0, findMaxPath(root.right, maxPath));
        int crossOverPath = root.val + leftPathSum + rightPathSum;

        maxPath[0] = Math.max(maxPath[0], crossOverPath);

        return root.val + Math.max(leftPathSum, rightPathSum);
    }

    public int maxPathSum(TreeNode root) {
        int[] maxPath = new int[1];
        maxPath[0] = Integer.MIN_VALUE;
        findMaxPath(root, maxPath);
        return maxPath[0];
    }
}