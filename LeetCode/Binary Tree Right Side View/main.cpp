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
    vector<int> rightSideView(TreeNode *root) {
        rightSideViewUtil(root, 0);
        vector<int> ans;
        for (const auto &ele : mp) {
            ans.push_back(ele.second);
        }
        return ans;
    }

   private:
    map<int, int> mp;

    void rightSideViewUtil(TreeNode *root, int depth) {
        if (root == nullptr) {
            return;
        }
        mp[depth] = root->val;
        rightSideViewUtil(root->left, depth + 1);
        rightSideViewUtil(root->right, depth + 1);
    }
};