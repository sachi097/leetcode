/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool func(TreeNode* root, ListNode* head)
    {
        if(!head->next)
        {
            if(!root) return false;
            return root->val == head->val;
        }
        if(root->left == nullptr && root->right== nullptr)
        return false;
        if(root->left && head->next && root->left->val == head->next->val)
        {
            if(func(root->left,head->next)) return true;
        }
        if(root->right && head->next && root->right->val == head->next->val)
        {
            if(func(root->right,head->next)) return true;
        }
        return false;
    }
    bool solve(TreeNode* root, ListNode* head)
    {
        if(!root) return false;
        if(root->val == head->val)
        {
            if(func(root,head)==true) return true;
        }
        if(solve(root->left,head)==true) return true;
        if(solve(root->right,head)==true) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        return solve(root,head);
    }
};