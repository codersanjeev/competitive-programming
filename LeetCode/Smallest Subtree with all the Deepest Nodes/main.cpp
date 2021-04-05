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
	TreeNode *subtreeWithAllDeepest(TreeNode *root) {
		if (root == nullptr) {
			return nullptr;
		}
		return findLevel(root).first;
	}

	pair<TreeNode *, int> findLevel(TreeNode *node) {
		if (node == nullptr) {
			return make_pair(node, 0);
		}
		pair<TreeNode *, int> left = findLevel(node->left);
		pair<TreeNode *, int> right = findLevel(node->right);
		if (left.second == right.second) {
			return make_pair(node, left.second + 1);
		} else if (left.second > right.second) {
			left.second++;
			return left;
		} else {
			right.second++;
			return right;
		}
	}

};