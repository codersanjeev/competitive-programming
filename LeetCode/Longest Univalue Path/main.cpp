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
	int longestUnivaluePath(TreeNode *root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		int left = dfs(root->left);
		int right = dfs(root->right);
		int currVal = 0, retVal = 0;
		if (root->left != nullptr && root->right != nullptr && root->left->val == root->val && root->right->val == root->val) {
			currVal = left + right + 2;
			retVal = 1 + max(left, right);
		} else if (root->left != nullptr && root->left->val == root->val) {
			currVal = left + 1;
			retVal = left + 1;
		} else if (root->right != nullptr && root->right->val == root->val) {
			currVal = right + 1;
			retVal = right + 1;
		} else {
			currVal = 0;
			retVal = 0;
		}
		ans = max(ans, currVal);
		return retVal;
	}

};