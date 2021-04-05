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

	TreeNode *curr;

	TreeNode *increasingBST(TreeNode *root) {
		TreeNode *ans = new TreeNode();
		curr = ans;
		increasingBSTUtil(root);
		return ans->right;
	}

	void increasingBSTUtil(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		increasingBSTUtil(node->left);
		node->left = nullptr;
		curr->right = node;
		curr = curr->right;
		increasingBSTUtil(node->right);
	}

};