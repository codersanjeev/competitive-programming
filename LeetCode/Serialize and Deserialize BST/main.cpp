/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:

	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		if (root == nullptr) {
			return "#,";
		}
		string left = serialize(root->left);
		string right = serialize(root->right);
		return to_string(root->val) + "," + left + right;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		queue<string> dataArray = splitData(data);
		return deserializeHelper(dataArray);
	}

  private:
	queue<string> splitData(const string &s) {
		istringstream ss(s);
		string word;
		queue<string> ans;
		while (getline(ss, word, ',')) {
			ans.push(word);
		}
		return ans;
	}

	TreeNode *deserializeHelper(queue<string> &dataArray) {
		if (dataArray.empty()) {
			return nullptr;
		}
		string val = dataArray.front();
		dataArray.pop();
		if (val == "#") {
			return nullptr;
		}
		TreeNode *node = new TreeNode(stoi(val));
		node->left = deserializeHelper(dataArray);
		node->right = deserializeHelper(dataArray);
		return node;
	}

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;