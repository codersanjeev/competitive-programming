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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		for (int i = 0; i < inorder.size(); i++) {
			mp[inorder[i]] = i;
		}
		return buildTreeUtil(preorder, inorder, 0, 0, inorder.size() - 1);
	}

  private:
	unordered_map<int, int> mp;

	// i: preorder current index
	// l: inorder left index
	// r: inorder right index
	TreeNode *buildTreeUtil(const vector<int> &preorder, const vector<int> &inorder, int i, int l, int r) {
		if (i >= preorder.size() || l > r) {
			return nullptr;
		}
		TreeNode *root = new TreeNode(preorder[i]);
		int j = mp[preorder[i]];
		root->left = buildTreeUtil(preorder, inorder, i + 1, l, j - 1);
		root->right = buildTreeUtil(preorder, inorder, i + j - l + 1, j + 1, r);
		return root;
	}
};