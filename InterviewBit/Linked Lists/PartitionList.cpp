/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::partition(ListNode *head, int x) {
	ListNode *lessList = new ListNode(0);
	ListNode *greaterList = new ListNode(0);
	ListNode *lessListHead = lessList;
	ListNode *greaterListHead = greaterList;
	while (head != NULL) {
		if (head->val >= x) {
			greaterList->next = new ListNode(head->val);
			greaterList = greaterList->next;
		} else {
			lessList->next = new ListNode(head->val);
			lessList = lessList->next;
		}
		head = head->next;
	}
	lessList->next = greaterListHead->next;
	return lessListHead->next;
}
