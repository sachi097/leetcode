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
        q.push(NULL);
        TreeNode* currentNode, *prevNode;
        while(q.size() > 1){
            currentNode = q.front();
            q.pop();
            if(!currentNode){
                rightView.push_back(prevNode->val);
                q.push(NULL);
            }
            else{
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                }
            }
            prevNode = currentNode;
        }
        rightView.push_back(prevNode->val);
        return rightView;
    }
};