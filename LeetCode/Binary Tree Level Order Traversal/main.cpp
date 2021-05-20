class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> curr;
            int cnt = q.size();
            while (cnt--) {
                TreeNode *node = q.front();
                q.pop();
                curr.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};