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
    TreeNode lca(TreeNode root, int a, int b){
        if(root == null){
            return null;
        }

        if(root.val == a || root.val == b){
            return root;
        }

        TreeNode leftLCA = lca(root.left, a, b);
        TreeNode rightLCA = lca(root.right, a, b);

        if(leftLCA != null && rightLCA != null){
            return root;
        }

        return leftLCA != null ? leftLCA : rightLCA;
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        int a=-1, b=-1;
        q.add(root);

        while(!q.isEmpty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode currNode = q.poll();
                if(i==0){
                    a = currNode.val;
                }

                if(i==size-1){
                    b = currNode.val;
                }

                if(currNode.left != null){
                    q.add(currNode.left);
                }

                if(currNode.right != null){
                    q.add(currNode.right);
                }
            }
        }

        return lca(root, a, b);
    }
}