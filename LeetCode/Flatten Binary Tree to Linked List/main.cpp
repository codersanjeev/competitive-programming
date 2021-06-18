class Solution {
   public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = previous;
        root->left = nullptr;
        previous = root;
    }

   private:
    TreeNode* previous = nullptr;
};