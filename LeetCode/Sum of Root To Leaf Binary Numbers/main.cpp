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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafUtility(root, 0);
    }

    int sumRootToLeafUtility(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        int nextSum = (sum * 2) + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return nextSum;
        }
        return sumRootToLeafUtility(root->left, nextSum) + sumRootToLeafUtility(root->right, nextSum);
    }
};