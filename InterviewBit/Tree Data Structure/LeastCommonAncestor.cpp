/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */

bool isPresent(TreeNode *root, int val) {
	if (root == NULL) {
		return false;
	}
	if (root->val == val) {
		return true;
	}
	return isPresent(root->left, val) || isPresent(root->right, val);
}

bool findLCA(TreeNode *root, TreeNode *&ans, int A, int B) {
	if (root == NULL) {
		return false;
	}
	if (root->val == A || root->val == B) {
		ans = root;
		return true;
	}
	bool left = findLCA(root->left, ans, A, B);
	bool right = findLCA(root->right, ans, A, B);
	if (left && right) {
		ans = root;
	}
	return left || right;
}


int Solution::lca(TreeNode *root, int A, int B) {
	TreeNode *ans = NULL;
	if (isPresent(root, A) && isPresent(root, B)) {
		findLCA(root, ans, A, B);
	}
	return ans != NULL ? ans->val : -1;
}

