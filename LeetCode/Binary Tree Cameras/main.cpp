class Solution {
   private:
    int cameraCount = 0;

    enum TreeNodeState : int {
        HAS_CAMERA = 0,
        COVERED,
        NOT_COVERED
    };

    TreeNodeState cover(TreeNode *root) {
        if (root == nullptr) return COVERED;
        TreeNodeState left = cover(root->left);
        TreeNodeState right = cover(root->right);
        if (left == NOT_COVERED || right == NOT_COVERED) {
            ++cameraCount;
            return HAS_CAMERA;
        }
        if (left == HAS_CAMERA || right == HAS_CAMERA)
            return COVERED;
        else
            return NOT_COVERED;
    }

   public:
    int minCameraCover(TreeNode *root) {
        return cover(root) == NOT_COVERED ? cameraCount + 1 : cameraCount;
    }
};