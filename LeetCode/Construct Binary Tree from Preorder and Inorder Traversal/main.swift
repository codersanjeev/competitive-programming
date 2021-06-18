class Solution {
	private var inorderIndexLookupTable = [Int: Int]()
	
	private func buildTreeRecursive(
        _ preorder: [Int],
        _ inorder: [Int],
        _ preorderIndex: Int,
        _ inorderStartIndex: Int,
        _ inorderEndIndex: Int
    ) -> TreeNode? {
		if preorderIndex >= preorder.count || inorderStartIndex > inorderEndIndex {
			return nil
		}
		let root = TreeNode(preorder[preorderIndex])
		let inorderMiddleIndex = inorderIndexLookupTable[preorder[preorderIndex]] ?? 0
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
	
	func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
		for i in inorder.indices {
			inorderIndexLookupTable[inorder[i]] = Int(i)
		}
		return buildTreeRecursive(preorder, inorder, 0, 0, inorder.count - 1)
	}
}