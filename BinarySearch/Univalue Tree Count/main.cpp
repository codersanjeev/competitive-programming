/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool isUnivalTree(Tree *root) {
	if (root == nullptr) {
		return true;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return true;
	}
	bool ok = true;
	if (root->left != nullptr && root->val != root->left->val) {
		ok = false;
	}
	if (root->right != nullptr && root->val != root->right->val) {
		ok = false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right) && ok;
}

int ans = 0;

void solveUtil(Tree *root) {
	if (root == nullptr) {
		return;
	}
	if (isUnivalTree(root)) {
		ans++;
	}
	solveUtil(root->left);
	solveUtil(root->right);
}

int solve(Tree *root) {
	ans = 0;
	solveUtil(root);
	return ans;
}