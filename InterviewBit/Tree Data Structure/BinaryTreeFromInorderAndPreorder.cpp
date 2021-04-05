/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preorder, inorder;
unordered_map<int, int> mp;
int i;

TreeNode *buildTreeUtil(int s, int e) {
	if (s > e) {
		return NULL;
	}
	int curr = preorder[i];
	i++;
	TreeNode *root = new TreeNode(curr);
	if (s == e) {
		return root;
	}
	int index = mp[curr];
	root->left = buildTreeUtil(s, index - 1);
	root->right = buildTreeUtil(index + 1, e);
	return root;
}

TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B) {
	preorder = A;
	inorder = B;
	for (int i = 0; i < inorder.size(); i++) {
		mp[inorder[i]] = i;
	}
	i = 0;
	return buildTreeUtil(0, preorder.size() - 1);
}
