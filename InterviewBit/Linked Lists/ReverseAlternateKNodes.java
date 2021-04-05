/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
	public ListNode solve(ListNode head, int k) {
		if (k <= 1 || head == null || head.next == null) {
			return head;
		}
		ListNode curr = head, prev = null, next = null;
		int cnt = 0;
		while (curr != null && cnt < k) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
			cnt++;
		}
		cnt = 0;
		if (next != null) {
			head.next = next;
			curr = next;
			while (curr != null && cnt < k - 1) {
				curr = curr.next;
				cnt++;
			}
			if (curr != null) {
				curr.next = solve(curr.next, k);
			}
		}
		return prev;
	}
}
