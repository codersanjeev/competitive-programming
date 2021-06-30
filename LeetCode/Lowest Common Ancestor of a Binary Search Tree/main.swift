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

    var level = [TreeNode : Int]()
    var parent = [TreeNode : TreeNode]()

    private func dfs(_ root: TreeNode?) {
        guard let root = root else { return }
        if let left = root.left {
            parent[left] = root
            level[left] = (level[root] ?? 0) + 1
            dfs(left)
        }
        if let right = root.right {
            parent[right] = root
            level[right] = (level[root] ?? 0) + 1
            dfs(right)
        }
    }

    func lowestCommonAncestor(_ root: TreeNode?, _ a: TreeNode?, _ b: TreeNode?) -> TreeNode? {
        parent[root] = root
        level[root] = 0
        dfs(root)
        var p = a
        var q = b
        if (level[p] ?? 0) < (level[q] ?? 0) {
            var temp = p
            p = q
            q = temp
        }
        var d = (level[p] ?? 0) - (level[q] ?? 0)
        while d > 0 {
            p = parent[p]
            d -= 1
        }
        if p == q { return p }
        while parent[p] != parent[q] {
            p = parent[p]
            q = parent[q]
        }
        return parent[p]
    }
}