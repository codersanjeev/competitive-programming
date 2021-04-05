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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		if (root == nullptr) {
			return {};
		}
		queue<TreeNode *> q;
		q.push(root);
		vector<vector<int>> answer;
		bool lr = true;
		while (!q.empty()) {
			int sz = q.size();
			answer.push_back(vector<int>(sz));
			for (int i = 0; i < sz; i++) {
				int idx = (lr ? i : sz - i - 1);
				answer.back()[idx] = q.front()->val;
				if (q.front()->left != nullptr) {
					q.push(q.front()->left);
				}
				if (q.front()->right != nullptr) {
					q.push(q.front()->right);
				}
				q.pop();
			}
			lr = !lr;
		}
		return answer;
	}
};