/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
	bool isCousins(TreeNode *root, int x, int y) {
		depth.resize(101);
		parent.resize(101);
		dfs(root);
		return depth[x] == depth[y] && parent[x] != parent[y];
	}
  private:
	vector<int> depth;
	vector<int> parent;

	void dfs(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		int val = root->val;
		if (root->left != nullptr) {
			parent[root->left->val] = val;
			depth[root->left->val] = 1 + depth[val];
		}
		if (root->right != nullptr) {
			parent[root->right->val] = val;
			depth[root->right->val] = 1 + depth[val];
		}
		dfs(root->left);
		dfs(root->right);
	}

};