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
    long answer = 0;
    int mod = (1e9 + 7);
    void kSumPaths(TreeNode* root, int k, long long prefixSum, unordered_map<long, long> &mp){
        if(!root){
            return;
        }
        
        prefixSum += root->val;
        if(mp.find(prefixSum - k) != mp.end()){
            answer = (answer + mp[prefixSum - k]) % mod;
        }
        
        mp[prefixSum]++;
        kSumPaths(root->left, k, prefixSum, mp);
        kSumPaths(root->right, k, prefixSum, mp);
        mp[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, long> mp;
        mp[0] = 1;
        kSumPaths(root, targetSum, 0, mp);
        return answer;
    }
};
        