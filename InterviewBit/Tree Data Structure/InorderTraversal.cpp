/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode *root) {
	stack<TreeNode *> st;
	vector<int> ans;
	while (root != NULL || !st.empty()) {
		while (root != NULL) {
			st.push(root);
			root = root->left;
		}
		root = st.top();
		st.pop();
		ans.push_back(root->val);
		root = root->right;
	}
	return ans;
}
