/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> inorder, postorder;
unordered_map<int, int> mp;
int i;

TreeNode *buildTreeUtil(int s, int e) {
	if (s > e) {
		return NULL;
	}
	int curr = postorder[i];
	i--;
	TreeNode *root = new TreeNode(curr);
	if (s == e) {
		return root;
	}
	int index = mp[curr];
	root->right = buildTreeUtil(index + 1, e);
	root->left = buildTreeUtil(s, index - 1);
	return root;
}

TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B) {
	inorder = A;
	postorder = B;
	for (int i = 0; i < inorder.size(); i++) {
		mp[inorder[i]] = i;
	}
	i = postorder.size() - 1;
	return buildTreeUtil(0, inorder.size() - 1);
}
