/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    void buildStringTree(TreeNode root, StringBuilder sb){
        if(root == null){
            sb.append("N ");
            return;
        }

        sb.append(Integer.toString(root.val) + " ");
        buildStringTree(root.left, sb);
        buildStringTree(root.right, sb);
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder tree = new StringBuilder();
        buildStringTree(root, tree);
        return tree.toString();
    }

    TreeNode buildTree(int[] idx, String[] data){
        idx[0]++;

        if(idx[0] >= data.length || data[idx[0]].equals("N")){
            return null;
        }

        String currNodeVal = data[idx[0]];

        TreeNode root = new TreeNode(Integer.parseInt(currNodeVal));
        root.left = buildTree(idx, data);
        root.right = buildTree(idx, data);

        return root;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] nodeValues = data.split(" ");
        int[] idx = new int[1];
        idx[0] = -1;
        return buildTree(idx, nodeValues);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));