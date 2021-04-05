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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root, voyage) ? ans : vector<int>{-1};
    }

   private:
    vector<int> ans;
    int index;

    bool dfs(TreeNode* root, const vector<int>& voyage) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != voyage[index++]) {
            return false;
        }
        if (root->left != nullptr && root->left->val != voyage[index]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        }
        return dfs(root->left, voyage) && dfs(root->right, voyage);
    }
};