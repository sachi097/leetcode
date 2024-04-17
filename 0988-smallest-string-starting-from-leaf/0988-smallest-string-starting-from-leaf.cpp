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
    void findString(TreeNode* root, string pathString, string &smallestString){
        if(!root){
            return;
        }
        pathString += char (97 + root->val);
        if(!root->left && !root->right){
            reverse(pathString.begin(), pathString.end());
            if(smallestString.compare("") == 0){
                smallestString = pathString;
            }
            else if(smallestString.compare(pathString) > 0){
                smallestString = pathString;
            }
        }
        findString(root->left, pathString, smallestString);
        findString(root->right, pathString, smallestString);
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        findString(root, "", smallestString);
        return smallestString;
    }
};