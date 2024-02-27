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

int findLongestPath(TreeNode* root, int &maxi){
    if(!root)
        return 0;
    int leftPath = findLongestPath(root->left, maxi);
    int rightPath = findLongestPath(root->right, maxi);
    maxi = max(maxi, leftPath + rightPath);
    return 1 + max(leftPath, rightPath);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        findLongestPath(root, maxi);
        return maxi;
    }
};