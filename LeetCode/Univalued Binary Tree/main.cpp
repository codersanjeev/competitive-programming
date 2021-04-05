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
	bool isUnivalTree(TreeNode *root) {
		if (root == nullptr) {
			return true;
		}
		if (root->left == nullptr && root->right == nullptr) {
			return true;
		}
		bool ok = true;
		if (root->left != nullptr && root->val != root->left->val) {
			ok = false;
		}
		if (root->right != nullptr && root->val != root->right->val) {
			ok = false;
		}
		return isUnivalTree(root->left) && isUnivalTree(root->right) && ok;
	}
};