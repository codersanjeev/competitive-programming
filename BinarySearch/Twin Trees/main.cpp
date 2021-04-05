/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree *root0, Tree *root1) {
	if (root0 == nullptr && root1 == nullptr) {
		return true;
	}
	if ((root0 == nullptr && root1 != nullptr) || (root0 != nullptr && root1 == nullptr)) {
		return false;
	}
	return root0->val == root1->val && solve(root0->left, root1->left) && solve(root0->right, root1->right);
}