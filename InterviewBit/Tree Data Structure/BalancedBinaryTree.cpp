/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int isBalancedUtil(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int left = isBalancedUtil(root->left);
	int right = isBalancedUtil(root->right);
	if (left != -1 && right != -1 && abs(left - right) <= 1) {
		return 1 + max(left, right);
	} else {
		return -1;
	}
}

int Solution::isBalanced(TreeNode *root) {
	if (isBalancedUtil(root) != -1) {
		return 1;
	} else {
		return 0;
	}
}
