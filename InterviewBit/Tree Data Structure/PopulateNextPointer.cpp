/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode *root) {
	if (root == NULL) {
		return;
	}
	queue<TreeLinkNode *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeLinkNode *curr = q.front();
		q.pop();
		if (curr == NULL) {
			if (q.empty()) {
				break;
			}
			q.push(NULL);
			continue;
		}
		curr->next = q.front();
		if (curr->left != NULL) {
			q.push(curr->left);
		}
		if (curr->right != NULL) {
			q.push(curr->right);
		}
	}
}
