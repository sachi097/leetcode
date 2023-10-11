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
    void findLeafSequence(TreeNode* root, vector<int>& leafSequence){
        if(!root) return;
        findLeafSequence(root->left, leafSequence);
        findLeafSequence(root->right, leafSequence);
        if(!root->left && !root->right){
            leafSequence.push_back(root->val);
            return;
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1LeafSequence, root2LeafSequence;
        findLeafSequence(root1, root1LeafSequence);
        findLeafSequence(root2,root2LeafSequence);
        return root1LeafSequence == root2LeafSequence;
    }
};