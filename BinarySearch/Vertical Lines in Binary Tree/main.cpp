/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree *root) {
	// root  = +0
	// left  = -1
	// right = +1
	queue<pair<Tree *, int>> q;
	int mx = INT_MIN, mn = INT_MAX;
	q.push({root, 0});
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		root = curr.first;
		mn = min(mn, curr.second);
		mx = max(mx, curr.second);
		if (root->left != nullptr) {
			q.push({root->left, curr.second - 1});
		}
		if (root->right != nullptr) {
			q.push({root->right, curr.second + 1});
		}
	}
	return mx - mn + 1;
}