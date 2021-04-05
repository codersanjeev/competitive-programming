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

	vector<TreeNode *> cache[21];

	vector<TreeNode *> allPossibleFBT(int n) {
		if (n % 2 == 0) {
			return vector<TreeNode *>(0);
		}
		if (n == 1) {
			return vector<TreeNode *>(1, new TreeNode());
		}
		if (cache[n].size() > 0) {
			return cache[n];
		}
		vector<TreeNode *> ans;
		for (int i = 1; i < n - 1; i += 2) {
			vector<TreeNode *> leftSubtrees = allPossibleFBT(i);
			vector<TreeNode *> rightSubtrees = allPossibleFBT(n - i - 1);
			for (const auto &left : leftSubtrees) {
				for (const auto &right : rightSubtrees) {
					TreeNode *root = new TreeNode();
					root->left = left;
					root->right = right;
					ans.push_back(root);
				}
			}
		}
		cache[n] = ans;
		return ans;
	}
};