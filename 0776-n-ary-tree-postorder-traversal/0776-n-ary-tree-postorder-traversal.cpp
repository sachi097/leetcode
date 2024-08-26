/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postntree(Node* root, vector<int>& ps){
        if(!root) return;
        for(auto ch: root->children){
            postntree(ch, ps);
        }
        ps.push_back(root->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> ps;
        postntree(root, ps);
        return ps;
    }
};