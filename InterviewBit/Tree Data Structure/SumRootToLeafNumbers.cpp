/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int mod = 1003;

int sumNumbersUtil(TreeNode *root, int curr) {
	if (root == NULL) {
		return 0;
	}
	curr = ((curr * 10) + root->val) % mod;
	if (root->left == NULL && root->right == NULL) {
		return curr % mod;
	}
	return (sumNumbersUtil(root->left, curr) % mod + sumNumbersUtil(root->right, curr) % mod) % mod;
}

int Solution::sumNumbers(TreeNode *root) {
	return sumNumbersUtil(root, 0);
}
