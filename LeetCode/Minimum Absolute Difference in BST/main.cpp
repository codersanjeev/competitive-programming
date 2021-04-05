class Solution {
  public:

	int ans = INT_MAX, previous = -1;

	int getMinimumDifference(TreeNode *root) {
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