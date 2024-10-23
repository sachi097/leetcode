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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return root;
        }

        queue<pair<TreeNode*, int>> q;

        q.push({root, root->val});
        int levelSum = root->val;

        while(!q.empty()){
            int size = q.size();
            int nextLevelSum = 0;

            for(int i=0; i<size; i++){
                auto top = q.front();
                q.pop();
                auto curr = top.first;
                
                int siblingSum = top.second;
                curr->val = levelSum - siblingSum;

                if(curr->left){
                    nextLevelSum += curr->left->val;
                    q.push({curr->left, curr->left->val + (curr->right ? curr->right->val : 0)});
                }
                if(curr->right){
                    nextLevelSum += curr->right->val;
                    q.push({curr->right, curr->right->val + (curr->left ? curr->left->val : 0)});
                }
            }
            levelSum = nextLevelSum;
        }

        return root;
    }
};