/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *flattenUtil(TreeNode *root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return root;
	}
	TreeNode *left = flattenUtil(root->left);
	TreeNode *right = flattenUtil(root->right);
	if (left != NULL) {
		left->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
	return right != NULL ? right : left;
}

TreeNode *Solution::flatten(TreeNode *root) {
	flattenUtil(root);
	return root;
}
