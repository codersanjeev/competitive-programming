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

	unordered_map<TreeNode *, int> level;
	unordered_map<TreeNode *, TreeNode *> parent;

	void dfs(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		if (root->left != nullptr) {
			parent[root->left] = root;
			level[root->left] = level[root] + 1;
			dfs(root->left);
		}
		if (root->right != nullptr) {
			parent[root->right] = root;
			level[root->right] = level[root] + 1;
			dfs(root->right);
		}
	}

	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		parent[root] = root;
		level[root] = 0;
		dfs(root);
		if (level[p] < level[q]) {
			swap(p, q);
		}
		int d = level[p] - level[q];
		while (d--) {
			p = parent[p];
		}
		if (p == q) {
			return p;
		}
		while (parent[p] != parent[q]) {
			p = parent[p];
			q = parent[q];
		}
		return parent[p];
	}
};