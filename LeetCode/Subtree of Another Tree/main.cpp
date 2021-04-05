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
	bool isSubtree(TreeNode *s, TreeNode *t) {
		return s != nullptr && (isIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
	}
  private:
	bool isIdentical(TreeNode *s, TreeNode *t) {
		if (s == nullptr && t == nullptr) {
			return true;
		}
		if (s == nullptr || t == nullptr) {
			return false;
		}
		return s->val == t->val && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
	}
};