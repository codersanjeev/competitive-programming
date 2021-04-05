TreeNode *Solution::solve(TreeNode *root) {
    if (root == nullptr) {
        return root;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    }
    TreeNode *left = solve(root->left);
    TreeNode *right = solve(root->right);
    if (root->left == nullptr) {
        return right;
    }
    if (root->right == nullptr) {
        return left;
    }
    root->left = left;
    root->right = right;
    return root;
}