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

	int ans;

	int dfs(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		int left = dfs(root->left);
		int right = dfs(root->right);
		ans = max(ans, left + right + root->val);
		return max(0, root->val + max(left, right));
	}

	int maxPathSum(TreeNode *root) {
		ans = INT_MIN;
		dfs(root);
		return ans;
	}
};