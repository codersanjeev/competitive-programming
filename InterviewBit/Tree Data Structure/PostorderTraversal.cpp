/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode *root) {
	stack<TreeNode *> s1, s2;
	s1.push(root);
	while (!s1.empty()) {
		root = s1.top();
		s1.pop();
		s2.push(root);
		if (root->left != NULL) {
			s1.push(root->left);
		}
		if (root->right != NULL) {
			s1.push(root->right);
		}
	}
	vector<int> ans;
	while (!s2.empty()) {
		root = s2.top();
		s2.pop();
		ans.push_back(root->val);
	}
	return ans;
}
