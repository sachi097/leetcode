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
    public int[] maxRobbing(TreeNode root){
        if(root == null){
            return new int[] {0, 0};
        }

        int[] leftRob = maxRobbing(root.left);
        int[] rightRob = maxRobbing(root.right);

        int[] result = new int[2];
        
        // rob current root & do not rob left and right child
        result[0] = root.val + leftRob[1] + rightRob[1];

        // do not rob current root but check max from robbing left right child or without robbing them
        result[1] = Math.max(leftRob[0], leftRob[1]) + Math.max(rightRob[0], rightRob[1]);

        return result;
    }

    public int rob(TreeNode root) {
        int[] maxRob = maxRobbing(root);

        return Math.max(maxRob[0], maxRob[1]);
    }
}