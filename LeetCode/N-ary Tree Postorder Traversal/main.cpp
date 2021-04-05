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
	vector<int> postorder(Node *root) {
		vector<int> ans;
		if (root == nullptr) {
			return ans;
		}
		postorderUtil(root, ans);
		return ans;
	}

  private:
	void postorderUtil(Node *root, vector<int> &ans) {
		if (root == nullptr) {
			return;
		}
		for (const auto &v : root->children) {
			postorderUtil(v, ans);
		}
		ans.push_back(root->val);
	}
};