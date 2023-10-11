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
    // this is needed outside to keep rootIndex within size of preorder 
    int rootIndex = 0;
    
    TreeNode* buildBT(vector<int>& preorder, vector<int>& inorder, int start, int end){
        // boundary condition when end < start i.e array out of bound
        if(end < start) return NULL;

        // pick root from preorder
        TreeNode* root = new TreeNode(preorder[rootIndex]);

        // increment rootIndex because next element in preorder will be the root for subtree
        rootIndex++;

        // find current root position in inorder and create left subtree and right subtree.
        // left subtree will have all the elements on the left of current root in inorder
        // right subtree will have all the elements on the right of current root in inorder
        auto rootIteratorInOrder = find(inorder.begin() + start, inorder.begin() + end, root->val);
        if(rootIteratorInOrder != inorder.end()){
            // left subtree end
            int newEnd = (rootIteratorInOrder - inorder.begin()) - 1;

            // right subtree start
            int newStart = (rootIteratorInOrder - inorder.begin()) + 1;

            //build left and right subtree of current root with newEnd and newStart
            root->left = buildBT(preorder,inorder, start, newEnd);
            root->right = buildBT(preorder,inorder, newStart, end);        
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildBT(preorder, inorder, 0, preorder.size() - 1);
    }
};