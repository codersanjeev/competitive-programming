bool traverse(TreeNode *root, int target, vector<int> &path) {
    if (root == nullptr) {
        return false;
    }
    path.push_back(root->val);
    if (root->val == target) {
        return true;
    }
    if (traverse(root->left, target, path) || traverse(root->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B) {
    vector<int> ans;
    traverse(A, B, ans);
    return ans;
}