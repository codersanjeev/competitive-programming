/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void f(TreeNode *root, vector<TreeNode *> &arr) {
	if (root == NULL) {
		return;
	}
	f(root->left, arr);
	arr.push_back(root);
	f(root->right, arr);
}

TreeNode *Solution::getSuccessor(TreeNode *root, int ele) {
	vector<TreeNode *> arr;
	f(root, arr);
	vector<int> arrr;
	for (auto ele : arr) {
		arrr.push_back(ele->val);
	}
	auto it = upper_bound(arrr.begin(), arrr.end(), ele);
	if (it == arrr.end()) {
		return NULL;
	}
	return arr[it - arrr.begin()];
}
