#include <vector>
using namespace std;

class Solution {
public:
    void find(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        find(root->left, ans);
        find(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        find(root, ans);
        return ans;
    }
};