/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *sortedArrayToBSTUtil(const vector<int> &arr, int lo, int hi) {
	if (lo > hi) {
		return NULL;
	}
	int mid = lo + (hi - lo) / 2;
	TreeNode *root = new TreeNode(arr[mid]);
	root->left = sortedArrayToBSTUtil(arr, lo, mid - 1);
	root->right = sortedArrayToBSTUtil(arr, mid + 1, hi);
	return root;
}

TreeNode *Solution::sortedArrayToBST(const vector<int> &arr) {
	return sortedArrayToBSTUtil(arr, 0, arr.size() - 1);
}
