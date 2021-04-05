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
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return ans;
    }

   private:
    int ans;
    double mn = DBL_MAX;

    void dfs(TreeNode* root, double target) {
        if (root == nullptr) {
            return;
        }
        int val = root->val;
        double diff = abs(target - val);
        if (diff < mn) {
            mn = diff;
            ans = val;
        }
        dfs(root->left, target);
        dfs(root->right, target);
    }
};