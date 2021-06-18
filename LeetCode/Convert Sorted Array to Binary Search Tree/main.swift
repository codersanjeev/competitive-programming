/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        return sortedArrayToBST(nums, 0, nums.count - 1)
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