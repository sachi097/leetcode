/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* findLCA(TreeNode* root, int p, int q){
        if(!root) return NULL;
        if(root->val == p || root->val == q){
            return root;
        }
        TreeNode* leftLCA = findLCA(root->left, p, q);
        TreeNode* rightLCA = findLCA(root->right, p, q);
        if(leftLCA && rightLCA)
            return root;
        return leftLCA ? leftLCA : rightLCA;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p->val, q->val);
    }
};