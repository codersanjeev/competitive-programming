/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *root, vector<int> &arr) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, arr);
	arr.push_back(root->val);
	inorder(root->right, arr);
}

int Solution::t2Sum(TreeNode *root, int k) {
	vector<int> arr;
	inorder(root, arr);
	int lo = 0, hi = arr.size() - 1;
	while (lo < hi) {
		int curr = arr[lo] + arr[hi];
		if (curr == k) {
			return 1;
		}
		curr < k ? lo++ : hi--;
	}
	return 0;
}
