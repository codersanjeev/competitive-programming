class Solution {
    func reverseBetween(_ head: ListNode?, _ left: Int, _ right: Int) -> ListNode? {
        let dummyNode = ListNode()
		dummyNode.next = head
		var previousNode: ListNode? = dummyNode
		var currentNode = dummyNode.next
		for _ in 1 ..< left {
			currentNode = currentNode?.next
			previousNode = previousNode?.next
		}
		for _ in 0 ..< right - left {
			let temporaryNode = currentNode?.next
			currentNode?.next = temporaryNode?.next
			temporaryNode?.next = previousNode?.next
			previousNode?.next = temporaryNode
		}
		return dummyNode.next
    }
}