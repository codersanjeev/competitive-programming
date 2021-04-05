/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
	Node *cloneGraph(Node *node) {
		if (node == nullptr) {
			return node;
		}
		if (mp[node] != nullptr) {
			return mp[node];
		}
		mp[node] = new Node(node->val);
		for (const auto &v : node->neighbors) {
			(mp[node]->neighbors).push_back(cloneGraph(v));
		}
		return mp[node];
	}

  private:
	unordered_map<Node *, Node *> mp;
};