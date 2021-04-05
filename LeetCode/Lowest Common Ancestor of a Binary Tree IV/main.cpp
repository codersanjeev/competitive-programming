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

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        parent[root] = root;
        level[root] = 0;
        dfs(root);
        TreeNode *ans = lca(root, nodes[0], nodes[0]);
        for (const auto &ele : nodes) {
            ans = lca(root, ans, ele);
        }
        return ans;
    }

   private:
    unordered_map<TreeNode *, int> level;
    unordered_map<TreeNode *, TreeNode *> parent;

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            parent[root->left] = root;
            level[root->left] = level[root] + 1;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            parent[root->right] = root;
            level[root->right] = level[root] + 1;
            dfs(root->right);
        }
    }

    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (level[p] < level[q]) {
            swap(p, q);
        }
        int d = level[p] - level[q];
        while (d--) {
            p = parent[p];
        }
        if (p == q) {
            return p;
        }
        while (parent[p] != parent[q]) {
            p = parent[p];
            q = parent[q];
        }
        return parent[p];
    }
};