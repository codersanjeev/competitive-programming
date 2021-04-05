/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;

int pathSum(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int left = max(0, pathSum(root->left));
	int right = max(0, pathSum(root->right));
	ans = max(ans, left + right + root->val);
	return max(left, right) + root->val;
}

int Solution::maxPathSum(TreeNode *root) {
	ans = INT_MIN;
	pathSum(root);
	return ans;
}
