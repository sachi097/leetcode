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
    
    map<int, map<int, vector<int>>> verticalNodesMap;
    
    void findVerticalNodes(TreeNode* root, int hd, int vd){
        if(!root) return;
        verticalNodesMap[hd][vd].push_back(root->val);
        findVerticalNodes(root->left, hd - 1, vd + 1);
        findVerticalNodes(root->right, hd + 1, vd + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        findVerticalNodes(root, 0, 0);
        vector<vector<int>> result;
        for(auto hd: verticalNodesMap){
            vector<int> tempVect;
            for(auto vd: hd.second){
                sort(vd.second.begin(), vd.second.end());
                tempVect.insert(tempVect.end(), vd.second.begin(), vd.second.end());
            }
            result.push_back(tempVect);
        }
        return result;
    }
};