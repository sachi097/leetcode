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
    void findLeftSum(TreeNode* root, int &sum, bool left){
        if(!root){
            return;
        }
        findLeftSum(root->left, sum, true);
        if(left && !root->left && !root->right){
            sum += root->val;
        }
        findLeftSum(root->right, sum, false);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findLeftSum(root, sum, false);
        return sum;
    }
};