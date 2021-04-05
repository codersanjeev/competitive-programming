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
	vector<int> preorder(Node *root) {
		vector<int> ans;
		if (root == nullptr) {
			return ans;
		}
		preorderUtil(root, ans);
		return ans;
	}
  private:
	void preorderUtil(Node *root, vector<int> &ans) {
		if (root == nullptr) {
			return;
		}
		ans.push_back(root->val);
		for (const auto &v : root->children) {
			preorderUtil(v, ans);
		}
	}
};