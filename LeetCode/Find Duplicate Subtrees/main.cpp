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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        vector<TreeNode *> ans;
        for (const auto &ele : mp) {
            if (ele.second > 1) {
                ans.push_back(deserialize(ele.first));
            }
        }
        return ans;
    }

   private:
    unordered_map<string, int> mp;

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        string s = serialize(root);
        mp[s]++;
        dfs(root->left);
        dfs(root->right);
    }

    vector<string> splitData(const string &s) {
        istringstream ss(s);
        string word;
        vector<string> ans;
        while (getline(ss, word, ',')) {
            ans.push_back(word);
        }
        return ans;
    }

    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        queue<TreeNode *> q;
        q.push(root);
        string ans = "";
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                ans += "#,";
                continue;
            }
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    TreeNode *deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<string> arr = splitData(data);
        TreeNode *root = new TreeNode(stoi(arr[0]));
        queue<TreeNode *> q;
        q.push(root);
        int index = 1;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (arr[index] != "#") {
                node->left = new TreeNode(stoi(arr[index]));
                q.push(node->left);
            }
            index++;
            if (arr[index] != "#") {
                node->right = new TreeNode(stoi(arr[index]));
                q.push(node->right);
            }
            index++;
        }
        return root;
    }
};