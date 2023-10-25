/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findPathSum(TreeNode* root, int remainingSum, int path){
        if(!root || remainingSum < -19999999) return 0;
        if(root->val == remainingSum){
            path++;
        }
        int leftPaths = findPathSum(root->left, remainingSum - root->val, 0);
        int rightPaths = findPathSum(root->right, remainingSum - root->val, 0);
        return path + leftPaths + rightPaths;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return findPathSum(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};