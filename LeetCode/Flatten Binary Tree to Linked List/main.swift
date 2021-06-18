class Solution {
	
	private var previous: TreeNode? = nil
	
	func flatten(_ root: TreeNode?) {
		if let root = root {
			flatten(root.right)
			flatten(root.left)
			root.right = previous
			root.left = nil
			previous = root
		}
	}
}
