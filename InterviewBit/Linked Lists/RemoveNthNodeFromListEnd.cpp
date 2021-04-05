/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::removeNthFromEnd(ListNode *A, int k) {
	int len = 0;
	ListNode *temp = A;
	while (temp != NULL) {
		len++;
		temp = temp->next;
	}
	if (k >= len) {
		return A->next;
	}
	int x = len - k - 1;
	temp = A;
	while (x--) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return A;
}
