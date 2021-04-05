/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
	vector<vector<int>> verticalTraversal(TreeNode *root) {
		queue<pair<TreeNode *, pair<int, int>>> q;
		map<int, map<int, set<int>>> nodes;
		q.push({root, {0, 0}});
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			TreeNode *node = curr.first;
			int x = curr.second.first, y = curr.second.second;
			nodes[x][y].insert(node->val);
			if (node->left != nullptr) {
				q.push({node->left, {x - 1, y + 1}});
			}
			if (node->right != nullptr) {
				q.push({node->right, {x + 1, y + 1}});
			}
		}
		vector<vector<int>> ans;
		for (const auto &ele : nodes) {
			vector<int> temp;
			for (const auto &x : ele.second) {
				temp.insert(temp.end(), x.second.begin(), x.second.end());
			}
			ans.push_back(temp);
		}
		return ans;
	}
};