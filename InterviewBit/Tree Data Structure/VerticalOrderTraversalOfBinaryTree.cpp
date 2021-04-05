vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A) {
    map<int, vector<int>> mp;
    vector<vector<int>> ans;
    if (A == nullptr) {
        return ans;
    }
    queue<pair<int, TreeNode *>> q;
    q.push({0, A});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        mp[curr.first].push_back(curr.second->val);
        if (curr.second->left != nullptr) {
            q.push({curr.first - 1, curr.second->left});
        }
        if (curr.second->right != nullptr) {
            q.push({curr.first + 1, curr.second->right});
        }
    }
    for (const auto &ele : mp) {
        ans.push_back(ele.second);
    }
    return ans;
}