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
    int rootI = 0;
    TreeNode* buildBT(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(end < start) return NULL;
        TreeNode* root = new TreeNode(preorder[rootI++]);
        auto rootIteratorInOrder = find(inorder.begin() + start, inorder.begin() + end, root->val);
        if(rootIteratorInOrder != inorder.end()){
                int newStart = (rootIteratorInOrder - inorder.begin()) + 1, newEnd = (rootIteratorInOrder - inorder.begin()) - 1;
                root->left = buildBT(preorder,inorder, start, newEnd);
                root->right = buildBT(preorder,inorder, newStart, end);        
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildBT(preorder, inorder, 0, preorder.size() - 1);
    }
};