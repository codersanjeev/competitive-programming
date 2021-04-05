/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void pathSumUtil(vector<vector<int>> &pResult, TreeNode *root, int sum, vector<int> &pList) {
	if (root == NULL) { return; }
	sum -= root->val;
	pList.push_back(root->val);
	if (root->left == NULL && root->right == NULL && sum == 0) { pResult.push_back(pList); }
	if (root->left)  { pathSumUtil(pResult, root->left,  sum, pList); }
	if (root->right) { pathSumUtil(pResult, root->right, sum, pList); }
	pList.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode *root, int sum) {
	vector<vector<int>> aResult;
	vector<int> aList;
	pathSumUtil(aResult, root, sum, aList);
	return aResult;
}
