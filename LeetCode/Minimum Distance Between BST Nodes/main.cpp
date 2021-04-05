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

	int ans = INT_MAX, previous = -1;

	int minDiffInBST(TreeNode *root) {
		minDiffInBSTUtil(root);
		return ans;
	}

	void minDiffInBSTUtil(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		minDiffInBSTUtil(node->left);
		if (previous != -1) {
			ans = min(ans, node->val - previous);
		}
		previous = node->val;
		minDiffInBSTUtil(node->right);
	}

};