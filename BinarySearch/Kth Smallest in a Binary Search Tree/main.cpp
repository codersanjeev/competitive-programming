/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void inorder(Tree *root, vector<int> &ans) {
	if (root == nullptr) {
		return;
	}
	inorder(root->left, ans);
	ans.push_back(root->val);
	inorder(root->right, ans);
}

int solve(Tree *root, int k) {
	vector<int> ans;
	inorder(root, ans);
	return ans[k];
}