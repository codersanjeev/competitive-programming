/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode *> generateTreesUtil(int start, int end) {
	vector<TreeNode *> ans;
	if (start > end) {
		ans.push_back(NULL);
		return ans;
	}
	for (int i = start; i <= end; i++) {
		vector<TreeNode *> left = generateTreesUtil(start, i - 1);
		vector<TreeNode *> right = generateTreesUtil(i + 1, end);
		for (auto l : left) {
			for (auto r : right) {
				TreeNode *root = new TreeNode(i);
				root->left = l;
				root->right = r;
				ans.push_back(root);
			}
		}
	}
	return ans;
}

vector<TreeNode *> Solution::generateTrees(int n) {
	return generateTreesUtil(1, n);
}
