/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        if (root == null || root == p || root == q) {
            return root
        }
        var left = lowestCommonAncestor(root.left, p, q)
        var right = lowestCommonAncestor(root.right, p, q)
        if (left == null && right == null) {
            return null
        } else if (left != null && right != null) {
            return root
        } else if (left == null) {
            return right
        } else {
            return left
        }
    }
}