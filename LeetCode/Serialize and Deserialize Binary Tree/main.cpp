/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
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

   private:
    vector<string> splitData(const string &s) {
        istringstream ss(s);
        string word;
        vector<string> ans;
        while (getline(ss, word, ',')) {
            ans.push_back(word);
        }
        return ans;
    }
};