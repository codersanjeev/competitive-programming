class Solution {
    private var inorderIndexLookupTable = HashMap<Int, Int>()

    private fun buildTreeRecursive(
        preorder: IntArray,
        inorder: IntArray,
        preorderIndex: Int,
        inorderStartIndex: Int,
        inorderEndIndex: Int
    ): TreeNode? {
        if (preorderIndex >= preorder.size || inorderStartIndex > inorderEndIndex) {
            return null
        }
        val root = TreeNode(preorder[preorderIndex])
        val inorderMiddleIndex = inorderIndexLookupTable[preorder[preorderIndex]] ?: 0
        root.left = buildTreeRecursive(
            preorder,
            inorder,
            preorderIndex + 1,
            inorderStartIndex,
            inorderMiddleIndex - 1
        )
        root.right = buildTreeRecursive(
            preorder,
            inorder,
            preorderIndex + inorderMiddleIndex - inorderStartIndex + 1,
            inorderMiddleIndex + 1,
            inorderEndIndex
        )
        return root
    }

    fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
        for (i in inorder.indices) {
            inorderIndexLookupTable[inorder[i]] = i
        }
        return buildTreeRecursive(preorder, inorder, 0, 0, inorder.size - 1)
    }
}