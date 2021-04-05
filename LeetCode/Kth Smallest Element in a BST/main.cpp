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
	int kthSmallest(TreeNode *root, int k) {
		vector<int> ans;
		kthSmallestUtil(root, ans);
		return ans[k - 1];
	}

  private:
	void kthSmallestUtil(TreeNode *root, vector<int> &ans) {
		if (root == nullptr) {
			return;
		}
		kthSmallestUtil(root->left, ans);
		ans.push_back(root->val);
		kthSmallestUtil(root->right, ans);
	}
};