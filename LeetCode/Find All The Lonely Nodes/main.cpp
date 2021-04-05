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
    vector<int> getLonelyNodes(TreeNode *root) {
        vector<int> ans;
        getLonelyNodesUtil(root, ans);
        return ans;
    }

   private:
    void getLonelyNodesUtil(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr && root->right == nullptr) {
            ans.push_back(root->left->val);
        }
        if (root->left == nullptr && root->right != nullptr) {
            ans.push_back(root->right->val);
        }
        getLonelyNodesUtil(root->left, ans);
        getLonelyNodesUtil(root->right, ans);
    }
};