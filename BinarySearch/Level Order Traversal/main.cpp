/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree *root) {
	vector<int> ans;
	queue<Tree *> q;
	if (root == nullptr) {
		return ans;
	}
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		ans.push_back(root->val);
		if (root->left != nullptr) {
			q.push(root->left);
		}
		if (root->right != nullptr) {
			q.push(root->right);
		}
	}
	return ans;
}