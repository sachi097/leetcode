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
    int maxDepth = 0;
    void findLongestZigZag(TreeNode* root, int depth, bool turnLeft){
        if(!root) return;
        if(turnLeft){
            findLongestZigZag(root->left, depth + 1, false);
            findLongestZigZag(root->right, 1, true); 
        }
        else{
            findLongestZigZag(root->right, depth + 1, true);
            findLongestZigZag(root->left, 1, false);
        }
        maxDepth = max(maxDepth, depth);
    }

    int longestZigZag(TreeNode* root) {
        findLongestZigZag(root, 0, true); 
        return maxDepth;
    }
};