/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode *A, TreeNode *B) {
	if (A == NULL && B == NULL) {
		return 1;
	}
	if (A != NULL && B != NULL) {
		return (A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right));
	}
	return 0;
}
