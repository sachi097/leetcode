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
class Node {
    TreeNode node;
    int depth;

    Node(TreeNode node, int depth){
        this.node = node;
        this.depth = depth;
    }
}

class Solution {
    public Node getSubTree(TreeNode root){
        if(root == null){
            return new Node(null, 0);
        }

        Node leftSubTree = getSubTree(root.left);
        Node rightSubTree = getSubTree(root.right);

        if(leftSubTree.depth == rightSubTree.depth){
            return new Node(root, 1 + leftSubTree.depth);
        }

        return new Node(leftSubTree.depth > rightSubTree.depth ? leftSubTree.node : rightSubTree.node, 1 + Math.max(leftSubTree.depth, rightSubTree.depth));

    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return getSubTree(root).node;
    }
}