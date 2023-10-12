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
        q.push(NULL);
        int maxSum = INT_MIN, maxSumLevel = 1, levelSum = 0, level = 1;
        while(q.size() > 1){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                if(levelSum > maxSum){
                    maxSum = levelSum;
                    maxSumLevel = level;
                }
                levelSum = 0;
                level++;
                q.push(NULL);
            }
            else{
                levelSum += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        if(levelSum > maxSum){
            maxSum = levelSum;
            maxSumLevel = level;
        }
        return maxSumLevel;
    }
};