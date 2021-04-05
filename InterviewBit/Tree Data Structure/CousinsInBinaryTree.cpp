const int N = 1e5 + 1;
vector<int> parent(N, -1);
vector<int> level(N, 0);

void dfs(TreeNode *root, int target, int p) {
    if (root == nullptr) {
        return;
    }
    parent[root->val] = p;
    level[root->val] = level[p] + 1;
    dfs(root->left, target, root->val);
    dfs(root->right, target, root->val);
}

void dfs(TreeNode *root, int target, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    if (parent[root->val] != parent[target] && level[root->val] == level[target]) {
        ans.push_back(root->val);
    }
    dfs(root->left, target, ans);
    dfs(root->right, target, ans);
}

vector<int> Solution::solve(TreeNode *A, int B) {
    vector<int> ans;
    dfs(A, B, 0);
    dfs(A, B, ans);
    return ans;
}