/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> ans;
	if (root == NULL) {
		return ans;
	}
	queue<TreeNode *> q;
	q.push(root);
	bool leftToRight = true;
	while (!q.empty()) {
		vector<int> temp;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			auto front = q.front();
			q.pop();
			temp.push_back(front->val);
			if (front->left != NULL) {
				q.push(front->left);
			}
			if (front->right != NULL) {
				q.push(front->right);
			}
		}
		if (leftToRight == false) {
			reverse(temp.begin(), temp.end());
		}
		ans.push_back(temp);
		leftToRight = !leftToRight;
	}
	return ans;
}
