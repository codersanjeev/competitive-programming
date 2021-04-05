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
    Node* findRoot(vector<Node*> tree) {
        int sum = 0;
        for (auto node : tree) {
            sum += node->val;
            for (auto child : node->children) {
                sum -= child->val;
            }
        }
        for (auto node : tree) {
            if (sum == node->val) {
                return node;
            }
        }
        return nullptr;
    }
};