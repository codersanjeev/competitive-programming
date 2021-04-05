/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
	vector<vector<int>> levelOrder(Node *root) {
		if (root == nullptr) {
			return {};
		}
		queue<pair<Node *, int>> q;
		const int M = 10001;
		vector<int> ans[M];
		q.push({root, 0});
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			root = curr.first;
			int level = curr.second;
			ans[level].push_back(root->val);
			for (const auto &v : root->children) {
				q.push({v, level + 1});
			}
		}
		vector<vector<int>> fans;
		for (const auto &ele : ans) {
			if (!ele.empty()) {
				fans.push_back(ele);
			}
		}
		return fans;
	}
};