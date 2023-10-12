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

unordered_map<TreeNode*, unordered_map<bool, int>> memo;  // Memoization table

int findLongestZigZag(TreeNode* root, bool turnLeft) {
    if (!root) return 0;

    if (memo.find(root) != memo.end() && memo[root].find(turnLeft) != memo[root].end()) {
        return memo[root][turnLeft];
    }

    int leftZigzag = 0, rightZigzag = 0;

    if (turnLeft) {
        if (root->left)
            leftZigzag = 1 + findLongestZigZag(root->left, false);
    } else {
        if (root->right)
            rightZigzag = 1 + findLongestZigZag(root->right, true);
    }

    memo[root][turnLeft] = max(leftZigzag, rightZigzag);
    return memo[root][turnLeft];
}

int longestZigZag(TreeNode* root) {
    if (!root) return 0;
    return max(findLongestZigZag(root, true), max(findLongestZigZag(root, false), max(longestZigZag(root->left), longestZigZag(root->right))));
}


};
