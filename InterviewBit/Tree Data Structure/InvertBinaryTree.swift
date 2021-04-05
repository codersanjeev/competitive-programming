import Foundation

/**
 * Definition for a binary tree node
 *
 * class TreeNode {
 *    var val: Int = 0
 *    var left: TreeNode?
 *    var right: TreeNode?
 * }
 *
 */

class Solution {
	func invertTree(_ root: TreeNode ? ) -> TreeNode ? {
		guard let root = root else {
			return nil
		}
		var left = invertTree(root.left)
		var right = invertTree(root.right)
		root.left = right
		root.right = left
		return root
	}
}
