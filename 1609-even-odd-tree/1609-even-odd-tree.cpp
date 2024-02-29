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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return false;
        TreeNode *currentNode;
        queue<TreeNode*> q;
        q.push(root);
        int minimum = INT_MAX, maximum = INT_MIN, size = 0;
        bool oddLevel = false;
        while(!q.empty()){
            size = q.size();
            minimum = INT_MAX, maximum = INT_MIN;
            for(auto i=0; i<size; i++){
                currentNode = q.front();
                q.pop();
                if(oddLevel){
                    if(minimum == currentNode->val)
                        return false;
                    minimum = min(minimum, currentNode->val);
                    if(minimum != currentNode->val || currentNode->val % 2 != 0)
                        return false;
                }
                else{
                    if(maximum == currentNode->val)
                        return false;
                    maximum = max(maximum, currentNode->val);
                    if(maximum != currentNode->val || currentNode->val % 2 == 0)
                        return false;
                }
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                }
            }
            oddLevel = !oddLevel;
        }
        return true;
    }
};