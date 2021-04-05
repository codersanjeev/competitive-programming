/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree *solve(Tree *root) {
	if (root == nullptr) {
		return root;
	}
	Tree *left = solve(root->left);
	Tree *right = solve(root->right);
	root->left = right;
	root->right = left;
	return root;
}