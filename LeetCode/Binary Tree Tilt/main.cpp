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

	int ans = 0;

	int findSum(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		return root->val + findSum(root->left) + findSum(root->right);
	}

	int findTilt(TreeNode *root) {
		ans = 0;
		if (root == nullptr) {
			return ans;
		}
		findTiltUtil(root);
		return ans;
	}

	void findTiltUtil(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		int lSum = findSum(root->left);
		int rSum = findSum(root->right);
		ans += abs(lSum - rSum);
		findTiltUtil(root->left);
		findTiltUtil(root->right);
	}

};