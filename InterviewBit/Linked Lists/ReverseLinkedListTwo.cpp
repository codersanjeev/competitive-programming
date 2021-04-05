/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
	if (head == NULL) {
		return head;
	}
	ListNode *curr = head;
	ListNode *prev = NULL;
	while (m > 1) {
		prev = curr;
		curr = curr->next;
		m--;
		n--;
	}
	ListNode *conn = prev;
	ListNode *tail = curr;
	ListNode *temp = NULL;
	while (n > 0) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		n--;
	}
	if (conn != NULL) {
		conn->next = prev;
	} else {
		head = prev;
	}
	tail->next = curr;
	return head;
}
