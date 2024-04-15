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
    int findSum(TreeNode* root, int pathSum){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return pathSum * 10 + root->val;
        }
        int leftSum = findSum(root->left, pathSum * 10 + root->val);
        int rightSum = findSum(root->right, pathSum * 10 + root->val);
        return leftSum + rightSum;
    }
    
    int sumNumbers(TreeNode* root) {
        return findSum(root, 0);
    }
};