/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::maxDepth(TreeNode *root) {
	return (root == NULL ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right)));
}
