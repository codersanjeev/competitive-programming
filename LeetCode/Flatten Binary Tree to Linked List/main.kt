
class Solution {

    private var previous: TreeNode? = null

    fun flatten(node: TreeNode?): Unit {
        node?.let { root ->
            flatten(root.right)
            flatten(root.left)
            root.right = previous
            root.left = null
            previous = root
        }
    }
}
