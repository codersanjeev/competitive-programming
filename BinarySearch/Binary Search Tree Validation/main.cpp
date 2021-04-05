/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool solveUtil(Tree *root, int mn, int mx) {
	if (root == nullptr) {
		return true;
	}
	int val = root->val;
	if (val < mn || val > mx) {
		return false;
	}
	return solveUtil(root->left, mn, val) && solveUtil(root->right, val, mx);
}

bool solve(Tree *root) {
	return solveUtil(root, INT_MIN, INT_MAX);
}