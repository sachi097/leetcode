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
    // TreeNode lca(TreeNode root, int a, int b){
    //     if(root == null){
    //         return null;
    //     }

    //     if(root.val == a || root.val == b){
    //         return root;
    //     }

    //     TreeNode leftLCA = lca(root.left, a, b);
    //     TreeNode rightLCA = lca(root.right, a, b);

    //     if(leftLCA != null && rightLCA != null){
    //         return root;
    //     }

    //     return leftLCA != null ? leftLCA : rightLCA;
    // }

    public Node getLCA(TreeNode root){
        if(root == null){
            return new Node(null, 0);
        }

        Node leftSubTree = getLCA(root.left);
        Node rightSubTree = getLCA(root.right);

        if(leftSubTree.depth == rightSubTree.depth){
            return new Node(root, 1 + leftSubTree.depth);
        }

        return new Node(leftSubTree.depth > rightSubTree.depth ? leftSubTree.node : rightSubTree.node, 1 + Math.max(leftSubTree.depth, rightSubTree.depth));

    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        // ArrayDeque<TreeNode> q = new ArrayDeque<>();
        // int a=-1, b=-1;
        // q.add(root);

        // while(!q.isEmpty()){
        //     int size = q.size();
        //     for(int i=0; i<size; i++){
        //         TreeNode currNode = q.poll();
        //         if(i==0){
        //             a = currNode.val;
        //         }

        //         if(i==size-1){
        //             b = currNode.val;
        //         }

        //         if(currNode.left != null){
        //             q.add(currNode.left);
        //         }

        //         if(currNode.right != null){
        //             q.add(currNode.right);
        //         }
        //     }
        // }

        // return lca(root, a, b);

        return getLCA(root).node;
    }
}