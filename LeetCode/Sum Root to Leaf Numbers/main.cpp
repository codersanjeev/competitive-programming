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
	int sumNumbers(TreeNode *root) {
		return sumNumbersUtil(root, 0);
	}

  private:
	int sumNumbersUtil(TreeNode *root, int sum) {
		if (root == nullptr) {
			return 0;
		}
		int nextSum = sum * 10 + root->val;;
		if (root->left == nullptr && root->right == nullptr) {
			return nextSum;
		}
		return sumNumbersUtil(root->left, nextSum) + sumNumbersUtil(root->right, nextSum);
	}
};