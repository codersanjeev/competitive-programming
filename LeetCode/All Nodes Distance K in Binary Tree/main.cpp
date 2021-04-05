/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
  public:


	const int N = 100001;
	vector<int> adj[100001];
	vector<bool> visited;

	void buildTree(TreeNode *root) {
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

	vector<int> distanceK(TreeNode *root, TreeNode *target, int radius) {
		visited.resize(N, false);
		buildTree(root);
		vector<int> ans;
		queue<pair<int, int>> q;
		q.push({target->val, 0});
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int u = curr.first;
			int d = curr.second;
			if (d == radius) {
				ans.push_back(u);
			}
			visited[u] = true;
			for (const auto &v : adj[u]) {
				if (visited[v] == false) {
					q.push({v, d + 1});
				}
			}
		}
		return ans;
	}
};