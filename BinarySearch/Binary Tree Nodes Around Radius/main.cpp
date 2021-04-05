/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

const int N = 100001;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void buildTree(Tree *root) {
	if (root == nullptr) {
		return;
	}
	int x = root->val, y = -1;
	if (root->left != nullptr) {
		y = root->left->val;
		adj[x].push_back(y);
		adj[y].push_back(x);
		buildTree(root->left);
	}
	if (root->right != nullptr) {
		y = root->right->val;
		adj[x].push_back(y);
		adj[y].push_back(x);
		buildTree(root->right);
	}
}

void dfs(int u, int r, int R, vector<int> &ans) {
	if (r == R) {
		ans.push_back(u);
	}
	// cout << u << '\t' << r << "\t" << R << '\n';
	visited[u] = true;
	for (const auto &v : adj[u]) {
		if (visited[v] == false) {
			dfs(v, r + 1, R, ans);
		}
	}
}

vector<int> solve(Tree *root, int target, int radius) {
	buildTree(root);
	vector<int> ans;
	dfs(target, 0, radius, ans);
	sort(ans.begin(), ans.end());
	return ans;
}