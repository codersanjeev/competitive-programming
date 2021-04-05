/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reverseList(ListNode *head, int k) {
	ListNode *curr = head;
	ListNode *prev = NULL;
	ListNode *next = NULL;
	int cnt = 0;
	while (curr != NULL && cnt < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}
	if (next != NULL) {
		head->next = reverseList(next, k);
	}
	return prev;
}
