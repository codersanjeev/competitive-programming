TreeNode *Solution::solve(TreeNode *A, TreeNode *B) {
    if (A == nullptr && B == nullptr) {
        return nullptr;
    }
    if (A == nullptr || B == nullptr) {
        return A == nullptr ? B : A;
    }
    int val = A->val + B->val;
    TreeNode *root = new TreeNode(val);
    root->left = solve(A->left, B->left);
    root->right = solve(A->right, B->right);
    return root;
}