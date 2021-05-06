class Solution {
    fun sortedListToBST(node: ListNode?): TreeNode? {
        var head = node
        val arr = mutableListOf<Int>()
        while (head != null) {
            arr.add(head.`val`)
            head = head.next
        }
        return sortedArrayToBST(arr, 0, arr.size - 1)
    }

    private fun sortedArrayToBST(arr: MutableList<Int>, lo: Int, hi: Int): TreeNode? {
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