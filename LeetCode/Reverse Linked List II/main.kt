class Solution {
    fun reverseBetween(head: ListNode?, left: Int, right: Int): ListNode? {
        val dummyNode = ListNode(-1)
        dummyNode.next = head
        var (previousNode, currentNode) = listOf(dummyNode, dummyNode.next)
        for (i in 1 until left) {
            currentNode = currentNode?.next
            previousNode = previousNode?.next
        }
        for (i in 0 until right - left) {
            val temporaryNode = currentNode?.next
            currentNode?.next = temporaryNode?.next
            temporaryNode?.next = previousNode?.next
            previousNode?.next = temporaryNode
        }
        return dummyNode.next
    }
}