class Solution {
	func sortedListToBST(_ node: ListNode?) -> TreeNode? {
		var head = node
		var arr = [Int]()
		while (head != nil) {
			arr.append(head?.val ?? 0)
			head = head?.next
		}
		return sortedArrayToBST(arr, 0, arr.count - 1)
	}
	
	private func sortedArrayToBST(_ arr: [Int], _ lo: Int, _ hi: Int) -> TreeNode? {
		if (lo > hi) {
			return nil
		}
		let mid = lo + (hi - lo) / 2
		let root = TreeNode(arr[mid])
		root.left = sortedArrayToBST(arr, lo, mid - 1)
		root.right = sortedArrayToBST(arr, mid + 1, hi)
		return root
	}
}
