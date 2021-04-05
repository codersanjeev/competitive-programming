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
	bool isSymmetric(TreeNode *root) {
		queue<TreeNode *> q;
		q.push(root);
		q.push(root);
		while (!q.empty()) {
			TreeNode *x = q.front();
			q.pop();
			TreeNode *y = q.front();
			q.pop();
			if (x == nullptr && y == nullptr) {
				continue;
			}
			if (x == nullptr || y == nullptr) {
				return false;
			}
			if (x->val != y->val) {
				return false;
			}
			q.push(x->left);
			q.push(y->right);
			q.push(x->right);
			q.push(y->left);
		}
		return true;
	}

  private:
	bool isMirror(TreeNode *x, TreeNode *y) {
		if (x == nullptr && y == nullptr) {
			return true;
		}
		if (x == nullptr || y == nullptr) {
			return false;
		}
		return x->val == y->val && isMirror(x->left, y->right) && isMirror(x->right, y->left);
	}
};