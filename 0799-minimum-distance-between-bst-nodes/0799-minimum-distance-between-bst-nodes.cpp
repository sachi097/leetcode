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
    void inorder(TreeNode*root, vector<int>&ans)
    {
        if(root)
        {
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return 0;
        vector<int>ans;
        inorder(root,ans);
       int mini = INT_MAX;

        for(int i = 0;i<ans.size()-1;++i)
            if(ans[i]!=ans[i+1]) mini = min(mini,ans[i+1]-ans[i]); 

        return mini;    
    }
};