/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int hasPathSumUtil(TreeNode *root, int target, int current) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return target == root->val + current;
	}
	return hasPathSumUtil(root->left, target, current + root->val) || hasPathSumUtil(root->right, target, current + root->val);
}

int Solution::hasPathSum(TreeNode *root, int target) {
	return hasPathSumUtil(root, target, 0);
}
