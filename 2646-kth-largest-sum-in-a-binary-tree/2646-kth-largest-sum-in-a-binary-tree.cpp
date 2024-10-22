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
    using ll =long long;

public:
    long long kthLargestLevelSum(TreeNode* a, int k) {
        priority_queue<ll,vector<ll>, greater<ll> >pq;

        queue<TreeNode*> q;
        q.push(a);
        while(!q.empty())
        {
            int sz=q.size();
            ll Sum=0;
            while(sz--)
            {
                a=q.front();q.pop();
                Sum+=a->val;
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
            }
            pq.push(Sum);
            if(pq.size()>k) pq.pop();
        }
        return pq.size()==k ? pq.top() : -1;
    }
};