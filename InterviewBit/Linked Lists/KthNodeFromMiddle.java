/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {

	public static int findLength(ListNode A) {
		int ans = 0;
		while (A != null) {
			ans++;
			A = A.next;
		}
		return ans;
	}

	public int solve(ListNode A, int B) {
		int N = findLength(A);
		int K = (N / 2) + 1;
		if (K > B) {
			int temp = K - B - 1;
			while (temp-- > 0) {
				A = A.next;
			}
			return A.val;
		}
		return -1;
	}
}
