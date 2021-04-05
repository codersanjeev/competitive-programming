vector<int> Solution::solve(TreeNode *A) {
    vector<int> ans;
    if (A == nullptr) {
        return ans;
    }
    deque<TreeNode *> q;
    q.push_front(A);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop_front();
        ans.push_back(node->val);
        if (node->left != nullptr) {
            q.push_back(node->left);
        }
        if (node->right != nullptr) {
            q.push_front(node->right);
        }
    }
    return ans;
}