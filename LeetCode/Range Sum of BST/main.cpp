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
	int rangeSumBST(TreeNode *root, int low, int high) {
		int ans = 0;
		if (root == nullptr) {
			return ans;
		}
		stack<TreeNode *> st;
		st.push(root);
		while (!st.empty()) {
			auto curr = st.top();
			st.pop();
			if (curr->val >= low && curr->val <= high) {
				ans += curr->val;
			}
			if (curr->left != nullptr && curr->val > low) {
				st.push(curr->left);
			}
			if (curr->right != nullptr && curr->val < high) {
				st.push(curr->right);
			}
		}
		return ans;
	}
};