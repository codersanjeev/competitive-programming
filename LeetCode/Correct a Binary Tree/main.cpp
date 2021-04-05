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
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (root == nullptr || found) {
            return root;
        }
        seen.insert(root->val);
        if (root->right != nullptr && seen.count(root->right->val) > 0) {
            found = true;
            return nullptr;
        }
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
        return root;
    }

   private:
    unordered_set<int> seen;
    bool found = false;
};