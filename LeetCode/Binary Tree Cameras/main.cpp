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
	// 0 1 2
	// H C P
	int minCameraCover(TreeNode *root) {
		return cover(root) == 2 ? ans + 1 : ans;
	}

  private:

	int ans = 0;

	int cover(TreeNode *root) {
		if (root == nullptr) {
			return 1;
		}
		int left = cover(root->left);
		int right = cover(root->right);
		if (left == 2 || right == 2) {
			ans++;
			return 0;
		}
		if (left == 0 || right == 0) {
			return 1;
		}
		return 2;
	}
};