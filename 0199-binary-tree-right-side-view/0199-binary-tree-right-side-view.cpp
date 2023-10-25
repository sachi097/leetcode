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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> rightView;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* currentNode, *prevNode;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                currentNode = q.front();
                q.pop();
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                }
                if(i==size-1){
                    rightView.push_back(currentNode->val);
                }
            }
        }
        return rightView;
    }
};