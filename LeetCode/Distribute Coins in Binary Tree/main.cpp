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
	int distributeCoins(TreeNode *root) {
		int ans = 0;
		distributeCoinsUtil(root, ans);
		return ans;
	}

  private:
	int distributeCoinsUtil(TreeNode *root, int &moves) {
		if (root == nullptr) {
			return 0;
		}
		int left = distributeCoinsUtil(root->left, moves);
		int right = distributeCoinsUtil(root->right, moves);
		moves += abs(left) + abs(right);
		return left + right + root->val - 1;
	}
};
