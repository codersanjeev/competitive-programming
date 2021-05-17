class Solution {
    private var cameraCount = 0

    enum class TreeNodeState { HAS_CAMERA, COVERED, NOT_COVERED }

    private fun cover(root: TreeNode?): TreeNodeState {
        if (root == null) return TreeNodeState.COVERED
        val left = cover(root.left)
        val right = cover(root.right)
        if (left == TreeNodeState.NOT_COVERED || right == TreeNodeState.NOT_COVERED) {
            ++cameraCount
            return TreeNodeState.HAS_CAMERA
        }
        return when {
            left == TreeNodeState.HAS_CAMERA || right == TreeNodeState.HAS_CAMERA -> TreeNodeState.COVERED
            else -> TreeNodeState.NOT_COVERED
        }
    }

    fun minCameraCover(root: TreeNode?): Int {
        return when (cover(root)) {
            TreeNodeState.NOT_COVERED -> ++cameraCount
            else -> cameraCount
        }
    }
}