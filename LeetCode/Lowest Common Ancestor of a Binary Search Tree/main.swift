/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ a: TreeNode?, _ b: TreeNode?) -> TreeNode? {
        if let root = root {
            if root.val == a?.val || root.val == b?.val { return root }
            var left = lowestCommonAncestor(root.left, a, b)
            var right = lowestCommonAncestor(root.right, a, b)
            if left == nil && right == nil { return nil }
            if left != nil && right != nil { return root }
            return left == nil ? right : left
        } else {
            return nil
        }
    }
}