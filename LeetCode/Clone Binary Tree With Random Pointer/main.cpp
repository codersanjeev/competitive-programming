/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
   public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto it = _cache.find(root);
        if (it != _cache.end()) {
            return it->second;
        }
        NodeCopy* newNode = new NodeCopy(root->val);
        _cache[root] = newNode;
        newNode->left = copyRandomBinaryTree(root->left);
        newNode->right = copyRandomBinaryTree(root->right);
        newNode->random = copyRandomBinaryTree(root->random);
        return newNode;
    }

   private:
    unordered_map<Node*, NodeCopy*> _cache;
};