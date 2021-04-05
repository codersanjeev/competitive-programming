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
    Node* cloneTree(Node* root) {
        if (root == nullptr) {
            return root;
        }
        if (mp[root] != nullptr) {
            return mp[root];
        }
        mp[root] = new Node(root->val);
        for (const auto& v : root->children) {
            (mp[root]->children).push_back(cloneTree(v));
        }
        return mp[root];
    }

   private:
    unordered_map<Node*, Node*> mp;
};