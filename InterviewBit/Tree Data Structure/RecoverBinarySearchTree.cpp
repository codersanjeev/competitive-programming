/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode *root) {
	TreeNode *first = NULL;
	TreeNode *second = NULL;
	TreeNode *prev = NULL;
	stack<TreeNode *> st;
	while (!st.empty() || root != NULL) {
		if (root != NULL) {
			st.push(root);
			root = root->left;
		} else {
			root = st.top();
			st.pop();
			if (prev != NULL && root->val <= prev->val) {
				if (first == NULL) {
					first = prev;
				}
				second = root;
			}
			prev = root;
			root = root->right;
		}
	}
	return vector<int> {min(first->val, second->val), max(first->val, second->val)};
}
