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
    TreeNode* rootParentNode;
    TreeNode* findReplacementNodeInRight(TreeNode* minNode){
        TreeNode* parentNode = minNode;
        while(minNode->left){
            parentNode = minNode;
            minNode = minNode->left;
        }
        if(parentNode != minNode){
            parentNode->left = minNode->right;
        }
        return minNode;
    }

    TreeNode* findReplacementNodeInLeft(TreeNode* maxNode){
        TreeNode* parentNode = maxNode;
        while(maxNode->right){
            parentNode = maxNode;
            maxNode = maxNode->right;
        }
        if(parentNode != maxNode){
            parentNode->right = maxNode->left;
        }
        return maxNode;
    }

    TreeNode* findNode(TreeNode* root, int key){
        rootParentNode = root;
        while(root){
            if(root->val > key){
                rootParentNode = root;
                root = root->left;
            }
            else if(root->val < key){
                rootParentNode = root;
                root = root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
        // if(!root || root->val == key) return root;
        // if(root->left && root->val > key){
        //     return findNode(root->left,key);
        // }
        // else{
        //    return findNode(root->right,key); 
        // }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* searchNode = findNode(root, key);
        if(searchNode && searchNode == root && !searchNode->right && !searchNode->left) return NULL;
        if(searchNode){
            TreeNode* replacementNode;
            if(searchNode->right){
                replacementNode = findReplacementNodeInRight(searchNode->right);
                if(replacementNode == searchNode->right){
                    searchNode->right = replacementNode->right;
                }
                searchNode->val = replacementNode->val;
            }
            else if(searchNode->left){
                replacementNode = findReplacementNodeInLeft(searchNode->left);
                if(replacementNode == searchNode->left){
                    searchNode->left = replacementNode->left;
                }
                searchNode->val = replacementNode->val;
            }
            else{
                if(rootParentNode->right == searchNode){
                    rootParentNode->right = NULL;
                }
                else{
                    rootParentNode->left = NULL;
                }
            }   
        }
        return root;
    }
};