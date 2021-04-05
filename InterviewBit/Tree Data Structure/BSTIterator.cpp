/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode *> st;

void insert(TreeNode *root) {
	while (root != NULL) {
		st.push(root);
		root = root->left;
	}
}

BSTIterator::BSTIterator(TreeNode *root) {
	st = stack<TreeNode *>();
	insert(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
	return st.size() != 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
	auto least = st.top();
	st.pop();
	insert(least->right);
	return least->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
