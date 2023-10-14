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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root != NULL){
            // If key is smaller than root->val, go left
            if(key < root->val) 
                root->left = deleteNode(root->left, key);
            // If key is larger than root->val, go right  
            else if(key > root->val) 
                root->right = deleteNode(root->right, key);  
            // If key == root->val     
            else{
                // For 0 child/ root is leaf node, return NULL
                if(root->left == NULL && root->right == NULL) 
                    return NULL; 
                // For 1 child, return the child present
                if (root->left == NULL || root->right == NULL)
                    return root->left ? root->left : root->right; 
                // For 2 children, find minimum of right side or maximum of left side
                // and put that value in root
                TreeNode* temp = root->left;
                while(temp->right != NULL) 
                    temp = temp->right; 
                root->val = temp->val;     
                root->left = deleteNode(root->left, temp->val); 
            }
        }
        return root;
    }
};