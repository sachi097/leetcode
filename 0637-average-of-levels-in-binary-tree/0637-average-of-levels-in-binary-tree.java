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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        List<Double> answer = new ArrayList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            int size = queue.size();
            double levelSum = 0;
            for(int i=0; i<size; i++){
                TreeNode currentNode = queue.poll();
                levelSum += currentNode.val;
                if(currentNode.left != null){
                    queue.add(currentNode.left);
                }
                if(currentNode.right != null){
                    queue.add(currentNode.right);
                }
            }

            answer.add((double) (levelSum / size));
        }
        return answer;
    }
}