/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findIndex(vector<int> &arr, int lo, int hi) {
	int ans = lo, mx = arr[lo];
	for (int i = lo; i <= hi; i++) {
		if (arr[i] > mx) {
			mx = arr[i];
			ans = i;
		}
	}
	return ans;
}

TreeNode *buildTreeUtil(vector<int> &arr, int lo, int hi) {
	if (lo > hi) {
		return NULL;
	}
	int mid = findIndex(arr, lo, hi);
	TreeNode *root = new TreeNode(arr[mid]);
	root->left = buildTreeUtil(arr, lo, mid - 1);
	root->right = buildTreeUtil(arr, mid + 1, hi);
	return root;
}

TreeNode *Solution::buildTree(vector<int> &A) {
	return buildTreeUtil(A, 0, A.size() - 1);
}
