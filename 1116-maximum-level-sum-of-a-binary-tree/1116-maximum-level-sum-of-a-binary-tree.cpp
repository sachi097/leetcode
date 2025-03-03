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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, maxSumLevel = 1, levelSum = 0, level = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* currNode = q.front();
                q.pop();
                levelSum += currNode->val;
                if(currNode->left){
                    q.push(currNode->left);
                }

                if(currNode->right){
                    q.push(currNode->right);
                }
            }

            if(maxSum < levelSum){
                maxSum = levelSum;
                maxSumLevel = level;
            }
            levelSum = 0;
            level++;
        }

        return maxSumLevel;
    }
};