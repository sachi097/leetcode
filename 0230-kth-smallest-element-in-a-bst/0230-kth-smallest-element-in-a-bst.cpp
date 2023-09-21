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
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root,k);
    }
    
    int inOrder(TreeNode* root, int &k){
        int val = INT_MIN;
        if(root){
            val = inOrder(root->left, k);
            k = k - 1;
            if(k == 0){
                return root->val;
            }
            if(val == INT_MIN){
                val = inOrder(root->right, k);
            }
        }
        return val;
    }
};