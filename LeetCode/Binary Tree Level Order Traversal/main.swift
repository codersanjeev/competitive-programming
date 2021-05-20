class Solution {
	func levelOrder(_ root: TreeNode?) -> [[Int]] {
		var (ans, q) = ([[Int]](), [TreeNode]())
		guard let root = root else { return ans }
		q.append(root)
		while (!q.isEmpty) {
			var (curr, cnt) = ([Int](), q.count)
			while (cnt > 0) {
				let node = q.removeFirst()
				curr.append(node.val)
				if let left = node.left {
					q.append(left)
				}
				if let right = node.right {
					q.append(right)
				}
				cnt -= 1
			}
			ans.append(curr)
		}
		return ans
	}
}
