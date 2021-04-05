/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::levelOrder(TreeNode *root) {
	vector<vector<int>> ans;
	if (root == NULL) {
		return ans;
	}
	queue<TreeNode *> q;
	q.push(root);
	q.push(NULL);
	vector<int> tempArr;
	while (q.size() > 1) {
		TreeNode *temp = q.front();
		q.pop();
		if (temp == NULL) {
			q.push(NULL);
			if (!tempArr.empty()) {
				ans.push_back(tempArr);
				tempArr.clear();
			}
		} else {
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
			tempArr.push_back(temp->val);
		}
	}
	ans.push_back(tempArr);
	return ans;
}
