/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode *root) {
	if (root == NULL) {
		return INT_MAX;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return 1 + min(minDepth(root->left), minDepth(root->right));
}
