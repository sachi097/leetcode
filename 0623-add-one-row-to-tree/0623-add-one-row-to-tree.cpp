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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        TreeNode* currentNode;
        if(depth == 1){
            currentNode = new TreeNode(val, root, nullptr);
            return currentNode;
        }
        int currentDepth = 1, size;
        q.push(root);
        while(q.size() > 0){
            size = q.size();
            for(auto i=0; i<size; i++){
                currentNode = q.front();
                q.pop();
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                }
                if(currentDepth == depth - 1){
                    TreeNode *leftSubtree = new TreeNode(val, currentNode->left, nullptr), *rightSubtree = new TreeNode(val, nullptr, currentNode->right);
                    currentNode->left = leftSubtree;
                    currentNode->right = rightSubtree;
                }
            }
            currentDepth++;
        }
        return root;
    }
};