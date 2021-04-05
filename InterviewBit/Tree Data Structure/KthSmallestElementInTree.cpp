/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void f(TreeNode *root, vector<int> &arr) {
	if (root == NULL) {
		return;
	}
	f(root->left, arr);
	arr.push_back(root->val);
	f(root->right, arr);
}

int Solution::kthsmallest(TreeNode *root, int k) {
	vector<int> arr;
	f(root, arr);
	return arr[k - 1];
}
