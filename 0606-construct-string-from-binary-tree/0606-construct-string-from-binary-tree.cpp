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
    
    void constructStr(TreeNode* root, string& str){
        if(!root) return;
        if(!root->left && !root->right){
            str += to_string(root->val);
            return;
        }
        str += to_string(root->val) ;
        str += "(";
        constructStr(root->left, str);
        str += ")";
        if(root->right){
            str += "(";
            constructStr(root->right, str);
            str += ")";
        }
    }
    
    string tree2str(TreeNode* root) {
        string str = "";
        constructStr(root, str);
        return str;
    }
};