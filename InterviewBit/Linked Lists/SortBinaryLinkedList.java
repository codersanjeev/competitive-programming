/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
	public ListNode solve(ListNode A) {
		int zero = 0, one = 0;
		while (A != null) {
			if (A.val == 0) {
				zero++;
			} else {
				one++;
			}
			A = A.next;
		}
		ListNode dummyHead = new ListNode(0);
		ListNode current = dummyHead;
		while (zero-- > 0) {
			current.next = new ListNode(0);
			current = current.next;
		}
		while (one-- > 0) {
			current.next = new ListNode(1);
			current = current.next;
		}
		return dummyHead.next;
	}
}
