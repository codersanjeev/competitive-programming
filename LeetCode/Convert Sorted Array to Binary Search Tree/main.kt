/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        return sortedArrayToBST(nums, 0, nums.size - 1)
    }
    
    private fun sortedArrayToBST(arr: IntArray, lo: Int, hi: Int): TreeNode? {
        if (lo > hi) {
            return null
        }
        val mid = lo + (hi - lo) / 2
        val root = TreeNode(arr[mid])
        root.left = sortedArrayToBST(arr, lo, mid - 1)
        root.right = sortedArrayToBST(arr, mid + 1, hi)
        return root
    }
}