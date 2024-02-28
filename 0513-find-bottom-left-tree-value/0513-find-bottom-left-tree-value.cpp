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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int leftMostValue = root->val, queueLength;
        TreeNode *currentNode, *prevNode;
        // level order traversal using for loop
        // while(!q.empty()){
        //     queueLength = q.size();
        //     for(auto i=0; i<queueLength; i++){
        //         currentNode = q.front();
        //         q.pop();
        //         if(i == 0){
        //             leftMostValue = currentNode->val;
        //         }
        //         if(currentNode->left){
        //             q.push(currentNode->left);
        //         }
        //         if(currentNode->right){
        //             q.push(currentNode->right);
        //         }
        //     }
        // }
        // level order traversal using for null pointer to indicate level end
        q.push(NULL);
        while(q.size() > 1){
            currentNode = q.front();
            q.pop();
            if(!currentNode){
                q.push(NULL);
            }
            else{
                if(!prevNode){
                    leftMostValue = currentNode->val;
                }
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                } 
            }
            prevNode = currentNode;
        }
        return leftMostValue;
    }
};