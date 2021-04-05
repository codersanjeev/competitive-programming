/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode *root) {
	stack<TreeNode *> st;
	st.push(root);
	vector<int> ans;
	while (!st.empty()) {
		root = st.top();
		st.pop();
		ans.push_back(root->val);
		if (root->right != NULL) {
			st.push(root->right);
		}
		if (root->left != NULL) {
			st.push(root->left);
		}
	}
	return ans;
}
