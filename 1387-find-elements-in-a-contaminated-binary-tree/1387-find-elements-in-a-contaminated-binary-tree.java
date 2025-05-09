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
class FindElements {
    TreeNode root;
    HashSet<Integer> set;
    public FindElements(TreeNode root) {
        this.root = root;
        root.val = 0;

        set = new HashSet<>();
        set.add(0);

        recoverTree(root);    
    }

    public void recoverTree(TreeNode root){
        if(root == null){
            return;
        }

        int x = root.val;
        set.add(x);

        if(root.left != null){
            root.left.val = 2 * x + 1; 
        }

        if(root.right != null){
            root.right.val = 2 * x + 2; 
        }

        recoverTree(root.left);
        recoverTree(root.right);
    }
    
    public boolean find(int target) {
        return set.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */