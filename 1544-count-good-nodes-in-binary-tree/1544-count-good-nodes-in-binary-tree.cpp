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

    int findGoodNodes(TreeNode* root, int maximumSoFar, int goodNodesNum){
        if(root->val >= maximumSoFar){
            maximumSoFar = root->val;
            goodNodesNum++;
        }
        int goodNodesOnLeft = 0, goodNodesOnRight = 0;
        if(root->left){
           goodNodesOnLeft = findGoodNodes(root->left, maximumSoFar, 0);
        }
        if(root->right){
            goodNodesOnRight = findGoodNodes(root->right, maximumSoFar, 0);
        }
        return goodNodesNum + goodNodesOnLeft + goodNodesOnRight;
    }

    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, INT_MIN, 0);
    }
};