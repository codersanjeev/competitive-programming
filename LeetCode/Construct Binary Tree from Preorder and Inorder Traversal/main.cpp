class Solution {
   private:
    unordered_map<int, int> inorderIndexLookupTable;

    TreeNode* buildTreeRecursive(
        const vector<int>& preorder,
        const vector<int>& inorder,
        int preorderIndex,
        int inorderStartIndex,
        int inorderEndIndex) {
        if (preorderIndex >= preorder.size() || inorderStartIndex > inorderEndIndex) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        int inorderMiddleIndex = inorderIndexLookupTable[preorder[preorderIndex]];
        root->left = buildTreeRecursive(
            preorder,
            inorder,
            preorderIndex + 1,
            inorderStartIndex,
            inorderMiddleIndex - 1);
        root->right = buildTreeRecursive(
            preorder,
            inorder,
            preorderIndex + inorderMiddleIndex - inorderStartIndex + 1,
            inorderMiddleIndex + 1,
            inorderEndIndex);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexLookupTable[inorder[i]] = i;
        }
        return buildTreeRecursive(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};