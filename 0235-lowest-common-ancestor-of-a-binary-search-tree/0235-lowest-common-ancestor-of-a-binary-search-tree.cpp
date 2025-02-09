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
        if((root->val > p && root->val < q) || (root->val > q && root->val < p) || root->val == p || root->val == q){
            return root;
        }
        if(root->val < p && root->val < q){
            return findLCA(root->right, p, q);
        }
        else{
            return findLCA(root->left, p, q);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p->val, q->val);
    }

};