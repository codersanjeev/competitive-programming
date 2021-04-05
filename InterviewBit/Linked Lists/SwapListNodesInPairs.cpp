/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs(ListNode *head) {
	if (head == NULL) {
		return head;
	}
	ListNode *prev = head;
	ListNode *curr = head->next;
	while (curr != NULL) {
		int temp = curr->val;
		curr->val = prev->val;
		prev->val = temp;
		prev = curr->next;
		if (prev != NULL) {
			curr = prev->next;
		} else {
			curr = NULL;
		}
	}
	return head;
}
